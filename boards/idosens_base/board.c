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
 * @brief       Board specific implementations for the idosens_remote board
 *
 * @author      Clément Monaton, Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
 *
 * @}
 */

#include "board.h"
#include "periph/gpio.h"


void board_init(void)
{
    /* initialize the CPU */
    cpu_init();
	//Leds init
	gpio_init(LED_RED1_PIN, GPIO_OUT);
    gpio_init(LED_RED2_PIN, GPIO_OUT);
    gpio_init(LED_GREEN1_PIN, GPIO_OUT);
	gpio_init(LED_GREEN2_PIN, GPIO_OUT);
    gpio_init(LED_BLUE1_PIN, GPIO_OUT);
    gpio_init(LED_BLUE2_PIN, GPIO_OUT);
    gpio_set(LED_RED1_PIN);
    gpio_set(LED_RED2_PIN);
    gpio_set(LED_GREEN1_PIN);
	gpio_set(LED_GREEN2_PIN);
    gpio_set(LED_BLUE1_PIN);
    gpio_set(LED_BLUE2_PIN);
    
}
