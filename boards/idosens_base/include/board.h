/*
 * Copyright (C) 2014-2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_fox
 * @{
 *
 * @file
 * @brief       Board specific definitions for the fox board
 *
 * @author      Alaeddine Weslati <alaeddine.weslati@inria.fr>
 * @author      Thomas Eichinger <thomas.eichinger@fu-berlin.de>
 * @author      Oliver Hahm <oliver.hahm@inria.fr>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#include "cpu.h"
#include "periph_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Xtimer configuration
 *
 * Tell the xtimer that we use a 16-bit peripheral timer
 * @{
 */
#define XTIMER_WIDTH        (16)

/**
 * @name    Set default configuration parameters for the SX127X driver
 *          Pins are adapted to STM32 Nucleo-64 boards.
 * @{
 */

#ifndef SX127X_PARAM_SPI
#define SX127X_PARAM_SPI                    (SPI_DEV(0))
#endif

#ifndef SX127X_PARAM_SPI_NSS
#define SX127X_PARAM_SPI_NSS                GPIO_PIN(PORT_B, 10)       /* D10 */
#endif

#ifndef SX127X_PARAM_RESET
#define SX127X_PARAM_RESET                  GPIO_PIN(PORT_B, 12)       /* A0 */
#endif

#ifndef SX127X_PARAM_DIO0
#define SX127X_PARAM_DIO0                   GPIO_PIN(PORT_E, 14)      /* D2 */
#endif

#ifndef SX127X_PARAM_DIO1
#define SX127X_PARAM_DIO1                   GPIO_PIN(PORT_E, 13)       /* D3 */
#endif

#ifndef SX127X_PARAM_DIO2
#define SX127X_PARAM_DIO2                   GPIO_PIN(PORT_E, 12)       /* D4 */
#endif

#ifndef SX127X_PARAM_DIO3
#define SX127X_PARAM_DIO3                   GPIO_PIN(PORT_E, 11)       /* D5 */
#endif

#ifndef SX127X_PARAM_PASELECT
#define SX127X_PARAM_PASELECT               (SX127X_PA_RFO)
#endif

#ifndef SX127X_PARAM_TX_SWITCH
#define SX127X_PARAM_TX_SWITCH              GPIO_UNDEF
#endif

#ifndef SX127X_PARAM_RX_SWITCH
#define SX127X_PARAM_RX_SWITCH              GPIO_UNDEF
#endif

#ifndef SX127X_PARAMS
#if defined(SX127X_USE_TX_SWITCH) || defined(SX127X_USE_RX_SWITCH)
#define SX127X_PARAMS             { .spi            = SX127X_PARAM_SPI,          \
                                    .nss_pin        = SX127X_PARAM_SPI_NSS,      \
                                    .reset_pin      = SX127X_PARAM_RESET,        \
                                    .dio0_pin       = SX127X_PARAM_DIO0,         \
                                    .dio1_pin       = SX127X_PARAM_DIO1,         \
                                    .dio2_pin       = SX127X_PARAM_DIO2,         \
                                    .dio3_pin       = SX127X_PARAM_DIO3,         \
                                    .rx_switch_pin  = SX127X_PARAM_RX_SWITCH,    \
                                    .tx_switch_pin  = SX127X_PARAM_TX_SWITCH,    \
                                    .paselect       = SX127X_PARAM_PASELECT }
#else
#define SX127X_PARAMS             { .spi       = SX127X_PARAM_SPI,          \
                                    .nss_pin   = SX127X_PARAM_SPI_NSS,      \
                                    .reset_pin = SX127X_PARAM_RESET,        \
                                    .dio0_pin  = SX127X_PARAM_DIO0,         \
                                    .dio1_pin  = SX127X_PARAM_DIO1,         \
                                    .dio2_pin  = SX127X_PARAM_DIO2,         \
                                    .dio3_pin  = SX127X_PARAM_DIO3,         \
                                    .paselect  = SX127X_PARAM_PASELECT }
#endif
#endif
/**@}*/



/**
 * @brief   Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
