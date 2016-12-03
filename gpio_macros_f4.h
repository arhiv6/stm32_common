#ifndef _GPIO_MACROS_F4_H
#define _GPIO_MACROS_F4_H

/*
 Данный набор макросов упрощает работу с GPIO портами микроконтроллеров STM32F4xx
 Протестировано на STM32F407

 За основу взято:
 http://we.easyelectronics.ru/STM32/udobnaya-nastroyka-gpio-portov.html#comment114408
 http://ziblog.ru/2012/09/09/linii-vvoda-vyivoda-stm32-chast-3.html
 http://we.easyelectronics.ru/Soft/preprocessor-c.html
 https://www.opennet.ru/docs/RUS/cpp/

 Определение GPIO должно выглядить так:
 #define PIN_NAME PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE
 PORT - A, B, C, D и тд
 PIN - номер бита в порте
 MODE - режим выхода
 SPEED - (актуально только для выхода)
 ALTERNATE - номер альтернативной функции
 DEFAULT_STATE - значение поумолчанию для настроенных на выход пинов

 Пример: #define LED1    C, 9, MODE_OUTPUT_PUSH_PULL, SPEED_2MHZ, AF0, 0
 Пример: #define BUTTON1 C, 8, MODE_INPUT_PULL_UP,    SPEED_2MHZ, AF0, 0

 Доступные операции:
 PIN_CONFIGURATION(PIN_NAME) - настройка gpio
 PIN_ON(PIN_NAME)            - включить (установка лог. 1)
 PIN_OFF(PIN_NAME)           - выключить (установка лог. 0)
 PIN_TOGGLE(PIN_NAME)        - переключить состояние
 PIN_ISSET_IN - состояние порта снаружи мирросхемы
 PIN_ISSET - состояние порта, установленное в микросхеме
 Последние два используются только в конструкциях вида if(PIN_ISSET(PIN_NAME))
*/

//--------------------------------------------------------------------------------------------------
// Доступные настройки GPIO

// Режимы
#define MODE_OUTPUT_PUSH_PULL               MODE_OUTPUT_PUSH_PULL
#define MODE_OUTPUT_OPEN_DRAIN              MODE_OUTPUT_OPEN_DRAIN
#define MODE_OUTPUT_OPEN_DRAIN_PULL_UP      MODE_OUTPUT_OPEN_DRAIN_PULL_UP
#define MODE_AF_PUSH_PULL                   MODE_AF_PUSH_PULL
#define MODE_AF_OPEN_DRAIN                  MODE_AF_OPEN_DRAIN
#define MODE_AF_OPEN_DRAIN_PULL_UP          MODE_AF_OPEN_DRAIN_PULL_UP
#define MODE_INPUT_FLOATING                 MODE_INPUT_FLOATING
#define MODE_INPUT_PULL_UP                  MODE_INPUT_PULL_UP
#define MODE_INPUT_PULL_DOWN                MODE_INPUT_PULL_DOWN
#define MODE_ANALOG                         MODE_ANALOG

// Скорости
#define SPEED_2MHZ                          0UL
#define SPEED_25MHZ                         1UL
#define SPEED_50MHZ                         2UL
#define SPEED_100MHZ                        3UL

// Альтернативные функции
#define AF0                                 0UL
#define AF1                                 1UL
#define AF2                                 2UL
#define AF3                                 3UL
#define AF4                                 4UL
#define AF5                                 5UL
#define AF6                                 6UL
#define AF7                                 7UL
#define AF8                                 8UL
#define AF9                                 9UL
#define AF10                                10UL
#define AF11                                11UL
#define AF12                                12UL
#define AF13                                13UL
#define AF14                                14UL
#define AF15                                15UL

//--------------------------------------------------------------------------------------------------
// Установка альтернативной функции GPIO

#define _SET_ALTERNATE_PIN0(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 0); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 0);

#define _SET_ALTERNATE_PIN1(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 4); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 4);

#define _SET_ALTERNATE_PIN2(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 8); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 8);

#define _SET_ALTERNATE_PIN3(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 12); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 12);

#define _SET_ALTERNATE_PIN4(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 16); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 16);

#define _SET_ALTERNATE_PIN5(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 20); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 20);

#define _SET_ALTERNATE_PIN6(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 24); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 24);

#define _SET_ALTERNATE_PIN7(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[0] &= ~(15UL << 28); \
    GPIO##PORT->AFR[0] |= ((ALTERNATE) << 28);

#define _SET_ALTERNATE_PIN8(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 0); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 0);

#define _SET_ALTERNATE_PIN9(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 4); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 4);

#define _SET_ALTERNATE_PIN10(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 8); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 8);

#define _SET_ALTERNATE_PIN11(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 12); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 12);

#define _SET_ALTERNATE_PIN12(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 16); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 16);

#define _SET_ALTERNATE_PIN13(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 20); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 20);

#define _SET_ALTERNATE_PIN14(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 24); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 24);

#define _SET_ALTERNATE_PIN15(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->AFR[1] &= ~(15UL << 28); \
    GPIO##PORT->AFR[1] |= ((ALTERNATE) << 28);

//--------------------------------------------------------------------------------------------------
// Установка параметров GPIO

#define _SET_PIN_INPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL));

#define _SET_PIN_OUTPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL)); \
    GPIO##PORT->MODER |= (1UL << (PIN * 2UL));

#define _SET_PIN_ALTERNATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL)); \
    GPIO##PORT->MODER |= (2UL << (PIN * 2UL));

#define _SET_PIN_ANALOG(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->MODER |= (3UL << (PIN * 2UL));

#define _SET_PIN_PUSHPULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->OTYPER &= ~(1UL << PIN);

#define _SET_PIN_OPENDRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->OTYPER |= (1UL << PIN);

#define _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL));

#define _SET_PIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL)); \
    GPIO##PORT->PUPDR |= (1UL << (PIN * 2UL));

#define _SET_PIN_PULL_DOWN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL)); \
    GPIO##PORT->PUPDR |= (2UL << (PIN * 2UL));

#define _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->OSPEEDR &= ~(3UL << (PIN * 2UL));  \
    GPIO##PORT->OSPEEDR |= (SPEED << (PIN * 2UL));

#define _SET_PIN_DEFAULT_STATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    GPIO##PORT->ODR = ( GPIO##PORT->ODR & (~(1UL << PIN)) ) | ((DEFAULT_STATE & 1UL) << PIN);
/* Это эквивалентно записи:
GPIO##PORT->ODR &= ~(1UL << PIN); \
GPIO##PORT->ODR |= ((DEFAULT_STATE & 1UL) << PIN);
но без промежуточных состояний порта */

//--------------------------------------------------------------------------------------------------
// Настройка режима GPIO

#define _SET_MODE_OUTPUT_PUSH_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_DEFAULT_STATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PUSHPULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OUTPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_OUTPUT_OPEN_DRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_DEFAULT_STATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OPENDRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OUTPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_OUTPUT_OPEN_DRAIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_DEFAULT_STATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OPENDRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OUTPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_AF_PUSH_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_ALTERNATE_PIN##PIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE); \
    _SET_PIN_ALTERNATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PUSHPULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_AF_OPEN_DRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_ALTERNATE_PIN##PIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE); \
    _SET_PIN_ALTERNATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OPENDRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_AF_OPEN_DRAIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_SPEED(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_ALTERNATE_PIN##PIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE); \
    _SET_PIN_ALTERNATE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_OPENDRAIN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_INPUT_FLOATING(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_INPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_INPUT_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PULL_UP(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_INPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_INPUT_PULL_DOWN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_PULL_DOWN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_INPUT(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

#define _SET_MODE_ANALOG(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_NO_PULL(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    _SET_PIN_ANALOG(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE)

//--------------------------------------------------------------------------------------------------
// Реализация макросов

#define _PIN_CONFIGURATION(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    do { _SET_##MODE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) } while (0)

#define _PIN_ON(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    do { GPIO##PORT->BSRR = (1UL << PIN); } while (0)

#define _PIN_OFF(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    do { GPIO##PORT->BSRR = (65536UL << PIN); } while (0)

#define _PIN_TOGGLE(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    do { GPIO##PORT->ODR ^= (1UL << PIN); } while (0)

//#define _PIN_ISSET_IN(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
//    ( GPIO##PORT->ODR & (1UL << PIN)) )

#define _PIN_ISSET(PORT, PIN, MODE, SPEED, ALTERNATE, DEFAULT_STATE) \
    ( GPIO##PORT->IDR & (1UL << PIN) )

//--------------------------------------------------------------------------------------------------
// Переопределение макросов

#define PIN_CONFIGURATION(PIN_DESCRIPTION)  _PIN_CONFIGURATION(PIN_DESCRIPTION)
#define PIN_ON(PIN_DESCRIPTION)             _PIN_ON(PIN_DESCRIPTION)
#define PIN_OFF(PIN_DESCRIPTION)            _PIN_OFF(PIN_DESCRIPTION)
#define PIN_TOGGLE(PIN_DESCRIPTION)         _PIN_TOGGLE(PIN_DESCRIPTION)
//#define PIN_ISSET_IN(PIN_DESCRIPTION)       _PIN_ISSET_IN(PIN_DESCRIPTION)
#define PIN_ISSET(PIN_DESCRIPTION)          _PIN_ISSET(PIN_DESCRIPTION)

#endif // _GPIO_MACROS_F4_H
