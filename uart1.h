#ifndef _UART1_H_
#define _UART1_H_

#include "common.h"

// Настройка и использование UART + кольцевой буфер
// по мотивам http://we.easyelectronics.ru/STM32/uart-usart-na-stm32l-stm32.html

//--------------------------------------------------------------------------------------------------

#define _UART_CLK               SystemCoreClock // частота тактирования модуля UART
#define _UART_BAUDRATE          115200          // скорость
#define _UART_USE_RING_BUFFER   1               // использовать (1) или нет (0) кольцевые буферы

#if (_UART_USE_RING_BUFFER)
    #define _UART_RX_BUFFER_SIZE    32          // размер буфера на прием
    #define _UART_TX_BUFFER_SIZE    32          // размер буфера на передачу
#endif

//--------------------------------------------------------------------------------------------------

void uart_init();
uint8_t uart_getChar(void);     // прием данных
void uart_putChar(uint8_t c) ;  // вывод символа

#endif // _UART1_H_
