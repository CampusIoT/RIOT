/*
 * Copyright (C) 2019 Laboratoire informatique de Grenoble
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_idosens_sensor
 * @brief       Support for the Idosens Sensor with stm32l151cb
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the Idosens Sensor board
 *
 * @author      Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

/* This board provides no LSE */
#ifndef CONFIG_BOARD_HAS_LSE
#define CONFIG_BOARD_HAS_LSE    1
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
        .dev      = USART1,
        .rcc_mask = RCC_APB2ENR_USART1EN,
        .rx_pin   = GPIO_PIN(PORT_B, 7),
        .tx_pin   = GPIO_PIN(PORT_B, 6),
        .rx_af    = GPIO_AF7,
        .tx_af    = GPIO_AF7,
        .bus      = APB2,
        .irqn     = USART1_IRQn
    }
};

#define UART_0_ISR          (isr_usart1)

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

/**
 * @name I2C configuration
  * @{
 */
static const i2c_conf_t i2c_config[] = {
    {
        .dev            = I2C1,
        .speed          = I2C_SPEED_NORMAL,
        .scl_pin        = GPIO_PIN(PORT_B, 8),
        .sda_pin        = GPIO_PIN(PORT_B, 9),
        .scl_af         = GPIO_AF4,
        .sda_af         = GPIO_AF4,
        .bus            = APB1,
        .rcc_mask       = RCC_APB1ENR_I2C1EN,
        .clk            = CLOCK_APB1,
        .irqn           = I2C1_EV_IRQn
    }
};

#define I2C_0_ISR           isr_i2c1_ev

#define I2C_NUMOF           ARRAY_SIZE(i2c_config)
/** @} */



#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
