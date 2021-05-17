/*
 * Copyright (C) 2021 LIG
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_idosens_base
 * @{
 *
 * @file
 * @brief       Configuration of CPU peripherals for Idosens Base board
 *
 * @author      Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H


/* This board provides an LSE */
#ifndef CONFIG_BOARD_HAS_LSE
#define CONFIG_BOARD_HAS_LSE    1
#endif

/* HSE is clocked at 16MHz */
#ifndef CONFIG_BOARD_HAS_HSE
#define CONFIG_BOARD_HAS_HSE    1
#endif
#define CLOCK_HSE               MHZ(8)

#define RTT_FREQUENCY RTT_MAX_FREQUENCY

#include <stdint.h>

#include "periph_cpu.h"
#include "clk_conf.h"
//#include "cfg_rtt_default.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM2,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM2EN,
        .bus      = APB1,
        .irqn     = TIM2_IRQn
    },
    {
        .dev      = TIM3,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM3EN,
        .bus      = APB1,
        .irqn     = TIM3_IRQn
    }
};

#define TIMER_0_ISR         isr_tim2
#define TIMER_1_ISR         isr_tim3

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev      = UART4,
        .rcc_mask = RCC_APB1ENR_UART4EN,
        .rx_pin   = GPIO_PIN(PORT_C, 11),
        .tx_pin   = GPIO_PIN(PORT_C, 10),
        .bus      = APB1,
        .irqn     = UART4_IRQn
    }
};

#define UART_0_ISR          (isr_uart4)

#define UART_NUMOF          ARRAY_SIZE(uart_config)


/**
 * @name    SPI configuration
 *
 */

static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI2,
        .mosi_pin = GPIO_PIN(PORT_B, 15),
        .miso_pin = GPIO_PIN(PORT_B, 14),
        .sclk_pin = GPIO_PIN(PORT_B, 13),
        .cs_pin   = GPIO_UNDEF,
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1
    },
    {
        .dev      = SPI1,
        .mosi_pin = GPIO_PIN(PORT_A, 7),
        .miso_pin = GPIO_PIN(PORT_A, 6),
        .sclk_pin = GPIO_PIN(PORT_A, 5),
        .cs_pin   = GPIO_UNDEF,
        .rccmask  = RCC_APB2ENR_SPI1EN,
        .apbbus   = APB2
    }
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)

/**
 * @name    ADC configuration
 * @{
 */
static const adc_conf_t adc_config[] = {
    { GPIO_PIN(PORT_A, 1), 0, 1 }
};

#define ADC_NUMOF           ARRAY_SIZE(adc_config)

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
