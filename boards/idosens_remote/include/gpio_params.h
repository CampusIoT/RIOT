/*
 * Copyright (C) 2019 Laboratoire informatique de Grenoble
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_idosens_remote
 * @{
 *
 * @file
 * @brief       Board specific configuration of direct mapped GPIOs
 *
 * @author      Germain Lemasson <germain.lemasson@univ-grenoble-alpes.fr>
 */

#ifndef GPIO_PARAMS_H
#define GPIO_PARAMS_H

#include "board.h"
#include "saul/periph.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief    GPIO pin configuration
 */
static const  saul_gpio_params_t saul_gpio_params[] =
{
    {
        .name = "LED(red)",
        .pin = LED0_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "LED(green)",
        .pin = LED1_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "LED(blue)",
        .pin = LED2_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "BTN ON",
        .pin  = BTN0_PIN,
        .mode = BTN0_MODE
    },
    {
        .name = "BTN OFF",
        .pin  = BTN1_PIN,
        .mode = BTN1_MODE
    }
};

#ifdef __cplusplus
}
#endif

#endif /* GPIO_PARAMS_H */
/** @} */
