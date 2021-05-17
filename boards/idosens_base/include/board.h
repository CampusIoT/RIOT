/*
 * Copyright (C) 2019 Laboratoire informatique de Grenoble
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_idosens_base
 * @{
 *
 * @file
 * @brief       Board specific definitions for the idosens_base board
 *
 * @author      Clément Monaton, Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
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


#define SX127X_PARAM_SPI                    (SPI_DEV(0))
#define SX127X_PARAM_SPI_NSS                GPIO_PIN(PORT_B, 10)       /* D10 */
#define SX127X_PARAM_RESET                  GPIO_PIN(PORT_B, 12)       /* A0 */
#define SX127X_PARAM_DIO0                   GPIO_PIN(PORT_E, 14)      /* D2 */
#define SX127X_PARAM_DIO1                   GPIO_PIN(PORT_E, 13)       /* D3 */
#define SX127X_PARAM_DIO2                   GPIO_PIN(PORT_E, 12)       /* D4 */
#define SX127X_PARAM_DIO3                   GPIO_PIN(PORT_E, 11)       /* D5 */


/**@}*/

//Boutons

#define BOUTON_VOLUME_PLUS_PIN			GPIO_PIN(PORT_D, 5)
#define BOUTON_VOLUME_PLUS_MODE  		GPIO_IN
#define BOUTON_VOLUME_MINUS_PIN			GPIO_PIN(PORT_D, 6)
#define BOUTON_VOLUME_MINUS_MODE		GPIO_IN
#define BOUTON_MODE_PIN 				GPIO_PIN(PORT_D, 8)
#define BOUTON_MODE_MODE 				GPIO_IN
#define BOUTON_FRONT_PIN 				GPIO_PIN(PORT_D, 15)
#define BOUTON_FRONT_MODE 				GPIO_IN



//Leds
#define LED_RED1_PIN				GPIO_PIN(PORT_D, 12)
#define LED_RED2_PIN				GPIO_PIN(PORT_A, 11)
#define LED_GREEN1_PIN				GPIO_PIN(PORT_A, 8)
#define LED_GREEN2_PIN				GPIO_PIN(PORT_D, 14)
#define LED_BLUE1_PIN				GPIO_PIN(PORT_D, 13)
#define LED_BLUE2_PIN				GPIO_PIN(PORT_A, 9)


#define LED_RED1_MASK           (1 << 12)
#define LED_RED2_MASK           (1 << 11)
#define LED2_GREEN1_MASK        (1 << 8)
#define LED2_GREEN2_MASK        (1 << 14)
#define LED_BLUE1_MASK			(1 << 13)
#define LED_BLUE2_MASK			(1 << 9)

#define LED_RED1_ON             (GPIOD->ODR &= ~LED_RED1_MASK)
#define LED_RED1_OFF            (GPIOD->ODR |=  LED_RED1_MASK)
#define LED_RED1_TOGGLE         (GPIOD->ODR ^=  LED_RED1_MASK)

#define LED_RED2_ON             (GPIOA->ODR &= ~LED_RED2_MASK)
#define LED_RED2_OFF            (GPIOA->ODR |=  LED_RED2_MASK)
#define LED_RED2_TOGGLE         (GPIOA->ODR ^=  LED_RED2_MASK)

#define LED_GREEN1_ON             (GPIOA->ODR &= ~LED_GREEN1_MASK)
#define LED_GREEN1_OFF            (GPIOA->ODR |=  LED_GREEN1_MASK)
#define LED_GREEN1_TOGGLE         (GPIOA->ODR ^=  LED_GREEN1_MASK)

#define LED_GREEN2_ON             (GPIOD->ODR &= ~LED_GREEN2_MASK)
#define LED_GREEN2_OFF            (GPIOD->ODR |=  LED_GREEN2_MASK)
#define LED_GREEN2_TOGGLE         (GPIOD->ODR ^=  LED_GREEN2_MASK)

#define LED_BLUE1_ON             (GPIOD->ODR &= ~LED_BLUE1_MASK)
#define LED_BLUE1_OFF            (GPIOD->ODR |=  LED_BLUE1_MASK)
#define LED_BLUE1_TOGGLE         (GPIOD->ODR ^=  LED_BLUE1_MASK)

#define LED_BLUE2_ON             (GPIOA->ODR &= ~LED_BLUE2_MASK)
#define LED_BLUE2_OFF            (GPIOA->ODR |=  LED_BLUE2_MASK)
#define LED_BLUE2_TOGGLE         (GPIOA->ODR ^=  LED_BLUE2_MASK)


#define AUDIO_SHDN_PIN              GPIO_PIN(PORT_C,1)


/**
 * @brief   Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
