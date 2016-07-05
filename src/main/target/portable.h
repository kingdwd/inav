#ifndef PORTABLE_H
#define PORTABLE_H

#pragma once
/*
 * Use this file to map mcu specific functions
 */

#include "platform.h"

#define MHz 1000000


#if defined(STM32F745xx) || defined(STM32F767xx)

    #define systemReset NVIC_SystemReset
    /// TODO: F7 is a bootloader needed?
    #define systemResetToBootloader NVIC_SystemReset

    #define MCU_SYS_CLK     (216*MHz)
    #define MCU_APB1_CLK    (MCU_SYS_CLK/4)
    #define MCU_APB2_CLK    (MCU_SYS_CLK/2)
    
    // Configure UART 1
    #define MCU_UART1_AF                    GPIO_AF7_USART1
    #define MCU_UART1_DMA_TX_STREAM         DMA2_Stream7
    #define MCU_UART1_DMA_TX_CHANNEL        DMA_CHANNEL_4
    #define MCU_UART1_DMA_TX_STREAM_IRQn    DMA2_Stream7_IRQn
    #define MCU_UART1_DMA_TX_IRQHandler     DMA2_Stream7_IRQHandler
    #define MCU_UART1_DMA_RX_STREAM         DMA2_Stream5
    #define MCU_UART1_DMA_RX_CHANNEL        DMA_CHANNEL_4
    #define MCU_UART1_DMA_RX_STREAM_IRQn    DMA2_Stream5_IRQn
    #define MCU_UART1_DMA_RX_IRQHandler     DMA2_Stream5_IRQHandler
    
    /// TODO: HAL Implement definitions for other uarts
    #define MCU_UART2_AF    GPIO_AF7_USART2
    #define MCU_UART3_AF    GPIO_AF7_USART3
    #define MCU_UART4_AF    GPIO_AF8_UART4
    #define MCU_UART5_AF    GPIO_AF8_USART5
    #define MCU_UART6_AF    GPIO_AF8_USART6
    
    // Config I2C
    #define MCU_I2C1_AF     GPIO_AF4_I2C1
    #define MCU_I2C2_AF     GPIO_AF4_I2C2
    #define MCU_I2C3_AF     GPIO_AF4_I2C3
    #define MCU_I2C4_AF     GPIO_AF4_I2C4
    
    // SPI
    #define MCU_SPI1_AF     GPIO_AF5_SPI1
    #define MCU_SPI1_CLK    MCU_APB2_CLK
    #define MCU_SPI1_SPEED  {SPI_BAUDRATEPRESCALER_128, SPI_BAUDRATEPRESCALER_16, SPI_BAUDRATEPRESCALER_8} //0.84Mhz, 6.75Mhz, 13.5Mhz
    
    #define MCU_SPI2_AF     GPIO_AF5_SPI2
    #define MCU_SPI2_CLK    MCU_APB1_CLK
    #define MCU_SPI2_SPEED  {SPI_BAUDRATEPRESCALER_64, SPI_BAUDRATEPRESCALER_8, SPI_BAUDRATEPRESCALER_4} //0.84Mhz, 6.75Mhz, 13.5Mhz

    #define MCU_SPI3_AF     GPIO_AF6_SPI3
    #define MCU_SPI3_CLK    MCU_APB1_CLK
    #define MCU_SPI3_SPEED  {SPI_BAUDRATEPRESCALER_64, SPI_BAUDRATEPRESCALER_8, SPI_BAUDRATEPRESCALER_4} //0.84Mhz, 6.75Mhz, 13.5Mhz


#endif


#endif // PORTABLE_H