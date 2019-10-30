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
 * @name    LED pin definitions and handlers
 * @{
 */
#define LED0_PIN            GPIO_PIN(PORT_B, 6)
#define LED1_PIN            GPIO_PIN(PORT_B, 9)
#define LED2_PIN            GPIO_PIN(PORT_B, 8)

#define LED0_MASK           (1 << 6)
#define LED1_MASK           (1 << 9)
#define LED2_MASK           (1 << 8)

#define LED0_ON             (GPIOB->ODR &= ~LED0_MASK)
#define LED0_OFF            (GPIOB->ODR |=  LED0_MASK)
#define LED0_TOGGLE         (GPIOB->ODR ^=  LED0_MASK)

#define LED1_ON             (GPIOB->ODR &= ~LED1_MASK)
#define LED1_OFF            (GPIOB->ODR |=  LED1_MASK)
#define LED1_TOGGLE         (GPIOB->ODR ^=  LED1_MASK)

#define LED2_ON             (GPIOB->ODR &= ~LED2_MASK)
#define LED2_OFF            (GPIOB->ODR |=  LED2_MASK)
#define LED2_TOGGLE         (GPIOB->ODR ^=  LED2_MASK)
/** @} */


/**
 * @name User button
 * @{
 */
#define BTN0_PIN            GPIO_PIN(PORT_B, 1)
#define BTN0_MODE           GPIO_IN

#define BTN1_PIN            GPIO_PIN(PORT_A, 8)
#define BTN1_MODE           GPIO_IN
/** @} */

/**
 * @name    sx1276 configuration
 * @{
 */

#define SX127X_PARAM_SPI                    (SPI_DEV(0))
#define SX127X_PARAM_SPI_NSS                GPIO_PIN(PORT_A, 12)

#define SX127X_PARAM_RESET                  GPIO_PIN(PORT_B, 2)
#define SX127X_PARAM_DIO0                   GPIO_PIN(PORT_B, 10)
#define SX127X_PARAM_DIO1                   GPIO_PIN(PORT_B, 11)
#define SX127X_PARAM_DIO2                   GPIO_PIN(PORT_B, 12)
#define SX127X_PARAM_DIO3                   GPIO_PIN(PORT_A, 9)
#define SX127X_PARAM_DIO4                   GPIO_PIN(PORT_A, 10)
#define SX127X_PARAM_DIO5                   GPIO_PIN(PORT_A, 11)

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
