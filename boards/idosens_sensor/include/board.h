/*
 * Copyright (C) 2019 Laboratoire informatique de Grenoble
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_idosens_remote
 * @{
 *
 * @file
 * @brief       Board specific definitions for the idosens_remote board
 *
 * @author      Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
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
 * @name    sx1276 configuration
 * @{
 */

#define SX127X_PARAM_SPI                    (SPI_DEV(0))
#define SX127X_PARAM_SPI_NSS                GPIO_PIN(PORT_B, 12)

#define SX127X_PARAM_RESET                  GPIO_PIN(PORT_B, 2)
#define SX127X_PARAM_DIO0                   GPIO_PIN(PORT_A, 12)
#define SX127X_PARAM_DIO1                   GPIO_PIN(PORT_A, 11)
#define SX127X_PARAM_DIO2                   GPIO_PIN(PORT_A, 10)
#define SX127X_PARAM_DIO3                   GPIO_PIN(PORT_A, 9)
#define SX127X_PARAM_DIO4                   GPIO_PIN(PORT_B, 10)
#define SX127X_PARAM_DIO5                   GPIO_PIN(PORT_B, 11)

/** @} */

/**
 * @brief   Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
