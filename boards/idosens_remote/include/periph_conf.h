/*
 * Copyright (C) 2019 Laboratoire informatique de Grenoble
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_idosens_remote
 * @brief       Support for the Idosens Remote with stm32l151cb
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the Idosens Remote board
 *
 * @author      Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

/* This board provides no LSE */
#ifndef CONFIG_BOARD_HAS_LSE
#define CONFIG_BOARD_HAS_LSE    0
#endif

/* HSE is clocked at 16MHz */
#ifndef CONFIG_BOARD_HAS_HSE
#define CONFIG_BOARD_HAS_HSE    1
#endif
#define CLOCK_HSE               MHZ(8)


#include "periph_cpu.h"
#include "clk_conf.h"
#include "cfg_timer_tim2.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name    xtimer configuration
 * @{
 */
#define XTIMER_WIDTH        (16)
#define XTIMER_BACKOFF      (50)
#define XTIMER_ISR_BACKOFF  (40)
/** @} */

 /**
 * @name   UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev      = USART2,
        .rcc_mask = RCC_APB1ENR_USART2EN,
        .rx_pin   = GPIO_PIN(PORT_A, 3),
        .tx_pin   = GPIO_PIN(PORT_A, 2),
        .rx_af    = GPIO_AF7,
        .tx_af    = GPIO_AF7,
        .bus      = APB1,
        .irqn     = USART2_IRQn
    }
};

#define UART_0_ISR          (isr_usart2)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name   SPI configuration
 *
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI2,
        .mosi_pin = GPIO_PIN(PORT_B, 15),
        .miso_pin = GPIO_PIN(PORT_B, 14),
        .sclk_pin = GPIO_PIN(PORT_B, 13),
        .cs_pin   = GPIO_UNDEF,
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1,
        .mosi_af  = GPIO_AF5,
        .miso_af  = GPIO_AF5,
        .sclk_af  = GPIO_AF5,
        .cs_af    = GPIO_AF5,
    }
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */


#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
