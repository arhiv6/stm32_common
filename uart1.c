#include "uart1.h"

//==================================================================================================

#if (_UART_USE_RING_BUFFER)
    // Буфер на прием
    static volatile uint8_t  rx_buffer[_UART_RX_BUFFER_SIZE];
    static volatile uint16_t rx_wr_index = 0;           // индекс хвоста буфера (куда писать данные)
    static volatile uint16_t rx_rd_index = 0;           // индекс начала буфера (откуда читать данные)
    static volatile uint16_t rx_counter = 0;            // количество данных в буфере
    static volatile uint8_t  rx_buffer_overflow = 0;    // TODO информация о переполнении буфера

    // Буфер на передачу
    static volatile uint8_t  tx_buffer[_UART_TX_BUFFER_SIZE];
    static volatile uint16_t tx_wr_index = 0;           // индекс хвоста буфера (куда писать данные)
    static volatile uint16_t tx_rd_index = 0;           // индекс начала буфера (откуда читать данные)
    static volatile uint16_t tx_counter = 0;            // количество данных в буфере
#endif

//--------------------------------------------------------------------------------------------------

void uart_init()
{

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;

    PIN_CONFIGURATION(UART_RX);
    PIN_CONFIGURATION(UART_TX);

    // USART_BBR = FCLK / BAUDRATE, но правильнее округлить до ближайшего
    // целого для этого умножаем на 2, прибавляем 1, делим на 2
    USART1->BRR = (2 * _UART_CLK / _UART_BAUDRATE + 1) >> 1;
    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;

#if (_UART_USE_RING_BUFFER)
    USART1->CR1 |= USART_CR1_RXNEIE | USART_CR1_TXEIE;      // Разрешаем прерывания TX ON, RX ON
    NVIC_EnableIRQ(USART1_IRQn);                            // Разрешаем прерывание USART11
#endif
}

//--------------------------------------------------------------------------------------------------

uint8_t uart_getChar(void)              //прием данных
{
    uint8_t data;                       //переменная для данных

#if (_UART_USE_RING_BUFFER)
    while (rx_counter == 0) {};         //если данных нет, ждем
    data = rx_buffer[rx_rd_index++];    //берем данные из буфера
    if (rx_rd_index == _UART_RX_BUFFER_SIZE)
    {
        rx_rd_index = 0;                //идем по кругу
    }
    USART1->CR1 &= ~USART_CR1_RXNEIE;   // запрещаем прерывание чтобы оно не помешало изменить переменную
    --rx_counter;                       // увеличиваем счетчик количества данных в буфере
    USART1->CR1 |= USART_CR1_RXNEIE;    // разрешаем прерывание
#else
    while (!(USART1->SR & USART_SR_RXNE)) {};   // Ждем поступления данных
    data = USART1->DR;                          // считываем данные
#endif

    return data;
}

//--------------------------------------------------------------------------------------------------

void uart_putChar(uint8_t c)            //вывод данных
{
#if (_UART_USE_RING_BUFFER)
    while (tx_counter == _UART_TX_BUFFER_SIZE) {};      // если буфер переполнен, ждем
    if (tx_counter || (!(USART1->SR & USART_SR_TXE)))   // если в буфере уже что-то есть или что-то уже передается
    {
        tx_buffer[tx_wr_index++] = c;                   // то кладем данные в буфер
        if (tx_wr_index == _UART_TX_BUFFER_SIZE)
        {
            tx_wr_index = 0;                        //идем по кругу
        }
        USART1->CR1 &= ~USART_CR1_TXEIE;            // запрещаем прерывание, чтобы оно не мешало
        ++tx_counter;                               // увеличиваем счетчик количества данных в буфере
        USART1->CR1 |= USART_CR1_TXEIE;             // разрешаем прерывание
    }
    else                                            //если USART1 свободен
    {
        while (!(USART1->SR & USART_SR_TXE)) {};    // Проверка что буфер на передачу опустел
        USART1->DR = c;                             // передаем данные без прерывания
    }

#else
    while (!(USART1->SR & USART_SR_TXE)) {};        // Проверка что буфер на передачу опустел
    USART1->DR = c;                                 // Передача данных
#endif
}

//--------------------------------------------------------------------------------------------------

#if (_UART_USE_RING_BUFFER)
void USART1_IRQHandler(void)
{
    if (USART1->SR & USART_SR_RXNE)                     // Прерывание по приему?
    {
        if ((USART1->SR & (USART_SR_NE | USART_SR_FE | USART_SR_PE | USART_SR_ORE)) == 0) //проверяем нет ли ошибок
        {
            rx_buffer[rx_wr_index++] = (uint8_t)(USART1->DR); //считываем данные в буфер, инкрементируя хвост буфера
            if (rx_wr_index == _UART_RX_BUFFER_SIZE)
            {
                rx_wr_index = 0;                        //идем по кругу
            }
            if (++rx_counter == _UART_RX_BUFFER_SIZE)   //переполнение буфера
            {
                rx_counter = 0;                         //начинаем сначала (удаляем все данные)
                rx_buffer_overflow = 1;                 //сообщаем о переполнении
            }
        }
        else
        {
            USART1->DR;                                 // вычитываем данные и на всякий случай
            USART1->SR &= ~USART_SR_RXNE;               // ещё и сбрасываем флаг прерывания
        }
    }

    if (USART1->SR & USART_SR_TXE)                      //прерывание по передачи
    {
        if (tx_counter)                                 //если есть что передать
        {
            --tx_counter;                               // уменьшаем количество не переданных данных
            USART1->DR = tx_buffer[tx_rd_index++];      //передаем данные инкрементируя хвост буфера
            if (tx_rd_index == _UART_TX_BUFFER_SIZE)
            {
                tx_rd_index = 0;                        //идем по кругу
            }
        }
        else                                            //если нечего передать,
        {
            USART1->CR1 &= ~USART_CR1_TXEIE;            //запрещаем прерывание по передачи
        }
    }

    if (USART1->SR & USART_SR_ORE)                      //прерывание по переполнению буфера
    {
        USART1->DR;                                     // вычитываем данные и на всякий случай
        USART1->SR &= ~USART_SR_ORE;                    // ещё и сбрасываем флаг прерывания
    }
}
#endif
