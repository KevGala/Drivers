/*****************************************************
 * FileName:        GPIO2023.h
 * Dependencies:	BSP.h, stdint.h, stdio.h, stdbool.h, unistd.h, math.h
 * Processor:       ESP32
 * Board:           ESP32
 * Program version: ECLIPSE IDE
 * Company:         TecNM /IT Chihuahua
 * Description:     PROTOTIPOS DE FUNCIONES DEL DRIVER
 * Authors:         Kevin Galaviz, Wendy Marquez, Mario Marcial y Raul Rodriguez
 * Nota:
 *  Created on: Junio 2023
 **************************************************/
/************************************************************************************************
 * * Copyright (C) 2023 by Kevin Galaviz - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/

#ifndef GPIO2023_H
#define GPIO2023_H
#pragma once

/* Archivos de cabecera importantes. */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

/* Board Support Package. */
#include "BSP.h"

/************************************************
DECLARACIÓN DE APUNTADORES PARA ACCESO A MEMORIA
 ************************************************/
extern volatile uint32_t * const gpio_out;
extern volatile uint32_t * const gpio_out1;
extern volatile uint32_t * const gpio_enable;
extern volatile uint32_t * const gpio_enable1;
extern volatile uint32_t * const gpio_in;
extern volatile uint32_t * const gpio_in1;
// Registros IO_MUX_REG
extern volatile uint32_t * const gpio12;
extern volatile uint32_t * const gpio13;
extern volatile uint32_t * const gpio14;
extern volatile uint32_t * const gpio15;
extern volatile uint32_t * const gpio23;
extern volatile uint32_t * const gpio25;
extern volatile uint32_t * const gpio26;
extern volatile uint32_t * const gpio32;
extern volatile uint32_t * const gpio33;
extern volatile uint32_t * const gpio34;
extern volatile uint32_t * const gpio35;
/************************************************
DECLARACIÓN DE MACROS.
 ************************************************/
/* Habilita GPIO como salida. */
#define GPIO_ENABLE_OUTPUT_BIT(B)	if(B<31) /* GPIO 0-31*/ *gpio_enable |= (int)pow((double)2,(double)B); \
									else /* GPIO 32-39*/ *gpio_enable1 |= (int)pow((double)2,(double)B);
/* Desabilita GPIO como salida. */
#define GPIO_DISABLE_OUTPUT_BIT(B)  if(B<31)  /* GPIO 0-31*/  *gpio_enable &= ~(int)pow((double)2,(double)B); \
									else /* GPIO 32-39*/ *gpio_enable1 &= ~(int)pow((double)2,(double)B);
/* Pone en alto GPIO. */
#define GPIO_SET_LEVEL_HIGH(B)		if(B<31)  /* GPIO 0-31*/  *gpio_out |= (int)pow((double)2,(double)B); \
									else /* GPIO 32-39*/ *gpio_out1 |= (int)pow((double)2,(double)B);
/* Pone en bajo GPIO. */
#define GPIO_SET_LEVEL_LOW(B)		if(B<31)  /* GPIO 0-31*/  *gpio_out &= ~(int)pow((double)2,(double)B); \
									else /* GPIO 32-39*/ *gpio_out1 &= ~(int)pow((double)2,(double)B);
/* Cambia el estado del GPIO. */
#define GPIO_SET_LEVEL_TOGGLE(B)	if(B<31)  /* GPIO 0-31*/  *gpio_out ^= (int)pow((double)2,(double)B); \
									else /* GPIO 32-39*/ *gpio_out1 ^= (int)pow((double)2,(double)B);
/* Lee el estado del GPIO. */
#define GPIO_GET_LEVEL_BIT(B)  *gpio_in & (int)pow((double)2,(double)B);	/* GPIO 0-31 */
#define GPIO_GET_LEVEL_BIT1(B)  *gpio_in1 & (int)pow((double)2,(double)B);	/* GPIO 32-39 */

/* Pone el nivel a un registro. */
#define REG_SET_LEVEL(REG,B,L)	 if(L)	*REG |= (int)pow((double)2,(double)B); \
								 else	*REG &= ~(int)pow((double)2,(double)B);

/* Configura con IO_MUX_REG una entrada */
#define REG_CONFIG_OUT(G)	/* MCU_OE Output enable of the pad in sleep mode. 1: enable output; 0: disable output. (R/W) */	REG_SET_LEVEL(G,0,1)  \
/* MCU_SEL Select the IO_MUX function for this signal. 0 selects Function 0, 1 selects Function 1, etc. */	REG_SET_LEVEL(G,12,0) \
																											REG_SET_LEVEL(G,13,1) \
																											REG_SET_LEVEL(G,14,0);
/* Configura con IO_MUX_REG una salida */
#define REG_CONFIG_IN(G)	/* MCU_OE Output enable of the pad in sleep mode. 1: enable output; 0: disable output. (R/W) */	REG_SET_LEVEL(G,9,1)  \
/* MCU_SEL Select the IO_MUX function for this signal. 0 selects Function 0, 1 selects Function 1, etc. */	REG_SET_LEVEL(G,12,0) \
																											REG_SET_LEVEL(G,13,1) \
																											REG_SET_LEVEL(G,14,0);

/************************************************
    PROTOTIPO DE FUNCIONES
************************************************/
/* Función para configurar GPIO. */
extern void GPIO_CONFIG(gpio_n_t gpio_num,  uint8_t e);
/* Función que establece un valor en un GPIO de salida. */
extern void GPIO_SET_LEVEL(gpio_n_t gpio_num, uint8_t level);
/* Función que retorna el valor de entrada de un GPIO. */
extern uint8_t GPIO_GET_LEVEL(gpio_n_t gpio_num);
/* Función que inicializa el módulo GPIO. */
extern void GPIO_init_board(void);
/* Función de parpadeo de todos los leds. */
extern void LEDS_BLINK(void);
#endif









