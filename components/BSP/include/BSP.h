/*****************************************************************************
 *  FileName:        BSP.h
 *  Dependencies:    driver/gpio.h
 *  Processor:       ESP32
 *  Board:           ESP32
 *  Program version: Eclipse
 *  Company:         TecNM /IT Chihuahua
 *  Description:     Incluye la capa de abstraccion de los drivers.
 *  Authors:         Kevin Galaviz, Wendy Marquez, Mario Marcial y Raul Rodirguez
 *   Created on:     Mayo 2023
 *   Updated:
  **/
/************************************************************************************************
 * * Copyright (C) 2023 by Kevin Galaviz - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/

#ifndef BSP_H
#define BSP_H
#pragma once

/************************************************
ENUMERACION PARA ACCESO A GPIO
 ************************************************/
typedef enum {
    GPIO_N_NC = -1,    /*!< Use to signal not connected to S/W */
    GPIO_N_0 = 0,     /*!< GPIO0, input and output */
    GPIO_N_1 = 1,     /*!< GPIO1, input and output */
    GPIO_N_2 = 2,     /*!< GPIO2, input and output */
    GPIO_N_3 = 3,     /*!< GPIO3, input and output */
    GPIO_N_4 = 4,     /*!< GPIO4, input and output */
    GPIO_N_5 = 5,     /*!< GPIO5, input and output */
    GPIO_N_6 = 6,     /*!< GPIO6, input and output */
    GPIO_N_7 = 7,     /*!< GPIO7, input and output */
    GPIO_N_8 = 8,     /*!< GPIO8, input and output */
    GPIO_N_9 = 9,     /*!< GPIO9, input and output */
    GPIO_N_10 = 10,   /*!< GPIO10, input and output */
    GPIO_N_11 = 11,   /*!< GPIO11, input and output */
    GPIO_N_12 = 12,   /*!< GPIO12, input and output */
    GPIO_N_13 = 13,   /*!< GPIO13, input and output */
    GPIO_N_14 = 14,   /*!< GPIO14, input and output */
    GPIO_N_15 = 15,   /*!< GPIO15, input and output */
    GPIO_N_16 = 16,   /*!< GPIO16, input and output */
    GPIO_N_17 = 17,   /*!< GPIO17, input and output */
    GPIO_N_18 = 18,   /*!< GPIO18, input and output */
    GPIO_N_19 = 19,   /*!< GPIO19, input and output */
    GPIO_N_20 = 20,   /*!< GPIO20, input and output */
    GPIO_N_21 = 21,   /*!< GPIO21, input and output */
    GPIO_N_22 = 22,   /*!< GPIO22, input and output */
    GPIO_N_23 = 23,   /*!< GPIO23, input and output */
    GPIO_N_25 = 25,   /*!< GPIO25, input and output */
    GPIO_N_26 = 26,   /*!< GPIO26, input and output */
    GPIO_N_27 = 27,   /*!< GPIO27, input and output */
    GPIO_N_28 = 28,   /*!< GPIO28, input and output */
    GPIO_N_29 = 29,   /*!< GPIO29, input and output */
    GPIO_N_30 = 30,   /*!< GPIO30, input and output */
    GPIO_N_31 = 31,   /*!< GPIO31, input and output */
    GPIO_N_32 = 32,   /*!< GPIO32, input and output */
    GPIO_N_33 = 33,   /*!< GPIO33, input and output */
    GPIO_N_34 = 34,   /*!< GPIO34, input mode only */
    GPIO_N_35 = 35,   /*!< GPIO35, input mode only */
    GPIO_N_36 = 36,   /*!< GPIO36, input mode only */
    GPIO_N_37 = 37,   /*!< GPIO37, input mode only */
    GPIO_N_38 = 38,   /*!< GPIO38, input mode only */
    GPIO_N_39 = 39,   /*!< GPIO39, input mode only */
    GPIO_N_MAX,
/** @endcond */
} gpio_n_t;

/************************************************
DefiniciÓn de botones.
 ************************************************/
#define BSP_BTN1 12		/*	BOTON 1 (GPIO12) */
#define BSP_BTN2 34		/*	BOTON 1 (GPIO34) */

#define BOARD_BTN_NORMAL_STATE_BTN2 0	// Estado normal del boton 2
/************************************************
Definición de led's plasmados en tarjeta.
************************************************/
#define BSP_LED0 18
#define BSP_LED1 5
#define BSP_LED2 17
#define BSP_LED3 16
#define BSP_LED4 4
#define BSP_LED5 2
#define BSP_LED6 15

#define BSP_LED_H 0		/* Led encendido */
#define BSP_LED_L 1		/* Led apagado   */

/****************************************************
Para configurar los GPIO como entrado o como salida
****************************************************/
#define GPIO_OUT 1
#define GPIO_IN 0

#endif	/* BSP_H_ */
