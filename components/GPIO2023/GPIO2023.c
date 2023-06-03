/*****************************************************
 * FileName:        GPIO2023.C
 * Dependencies:	GPIO2023.h
 * Processor:       ESP32
 * Board:           ESP32
 * Program version: ECLIPSE IDE
 * Company:         TecNM /IT Chihuahua
 * Description:     FUNCIONES DEL DRIVER
 * Authors:         Kevin Galaviz, Wendy Marquez, Mario Marcial y Raul Rodirguez
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
#include "GPIO2023.h"
/************************************************
DECLARACIÓN DE APUNTADORES PARA ACCESO A MEMORIA
 ************************************************/
volatile uint32_t * const gpio_out  = (uint32_t*)0x3FF44004;
volatile uint32_t * const gpio_out1  = (uint32_t*)0x3FF44010;
volatile uint32_t * const gpio_enable = (uint32_t*)0x3FF44020;
volatile uint32_t * const gpio_enable1 = (uint32_t*)0x3FF4402C;
volatile uint32_t * const gpio_in  = (uint32_t*)0x3FF4403C;
volatile uint32_t * const gpio_in1  = (uint32_t*)0x3FF44040;
// Registros IO_MUX_REG
volatile uint32_t * const gpio12  = (uint32_t*)0x3ff49034;
volatile uint32_t * const gpio13  = (uint32_t*)0x3ff49038;
volatile uint32_t * const gpio14  = (uint32_t*)0x3FF49030;
volatile uint32_t * const gpio15  = (uint32_t*)0x3ff4903c;
volatile uint32_t * const gpio23  = (uint32_t*)0x3ff4908c;
volatile uint32_t * const gpio25  = (uint32_t*)0x3FF49024;
volatile uint32_t * const gpio26  = (uint32_t*)0x3ff49028;
volatile uint32_t * const gpio32  = (uint32_t*)0x3FF4901C;
volatile uint32_t * const gpio33  = (uint32_t*)0x3FF49020;
volatile uint32_t * const gpio34  = (uint32_t*)0x3ff49014;
volatile uint32_t * const gpio35  = (uint32_t*)0x3FF49018;
/*****************************************************************************
 * Function: GPIO_CONFIG
 * Preconditions: None.
 * Overview: Función configurar los GPIO.
 * Input: Número de GPIO, e = 1 salida, e = 0 entrada
 * Output: None.
 *
 *****************************************************************************/
void GPIO_CONFIG(gpio_n_t gpio_num,  uint8_t e)
{
	// Configuración de salida
	if(e){
		GPIO_ENABLE_OUTPUT_BIT(gpio_num)

		switch ((int)gpio_num)
		{
			case 12: REG_CONFIG_OUT(gpio12) break;
			case 13: REG_CONFIG_OUT(gpio13) break;
			case 14: REG_CONFIG_OUT(gpio14) break;
			case 15: REG_CONFIG_OUT(gpio15) break;
			case 23: REG_CONFIG_OUT(gpio23) break;
			case 25: REG_CONFIG_OUT(gpio25) break;
			case 26: REG_CONFIG_OUT(gpio26) break;
			case 32: REG_CONFIG_OUT(gpio32) break;
			case 33: REG_CONFIG_OUT(gpio33) break;
			case 34: REG_CONFIG_OUT(gpio34) break;
			case 35: REG_CONFIG_OUT(gpio35) break;
		}
	}
	// Configuaración de entrada
	else{
		GPIO_DISABLE_OUTPUT_BIT(gpio_num)

		switch ((int)gpio_num)
		{
			case 12: REG_CONFIG_IN(gpio12) break;
			case 13: REG_CONFIG_IN(gpio13) break;
			case 14: REG_CONFIG_IN(gpio14) break;
			case 15: REG_CONFIG_IN(gpio15) break;
			case 23: REG_CONFIG_IN(gpio23) break;
			case 25: REG_CONFIG_IN(gpio25) break;
			case 26: REG_CONFIG_IN(gpio26) break;
			case 32: REG_CONFIG_IN(gpio32) break;
			case 33: REG_CONFIG_IN(gpio33) break;
			case 34: REG_CONFIG_IN(gpio34) break;
			case 35: REG_CONFIG_IN(gpio35) break;
		}
	}
}
/******************************************************************************
 * Function: GPIO_SET_LEVEL
 * Preconditions: Ninguna.
 * Overview: Establece el valor de una salida.
 * Input: Numero del GPIO, estado.
 * Output: Ninguna.
 *
 *****************************************************************************/
void GPIO_SET_LEVEL(gpio_n_t gpio_num, uint8_t level)
{
	if(level) GPIO_SET_LEVEL_HIGH(gpio_num)	/* Pone en alto el gpio*/
	else GPIO_SET_LEVEL_LOW(gpio_num) /* Pone en bajo el gpio */
}
/*****************************************************************************
 * Function: GPIO_GET_LEVEL
 * Preconditions: Ninguna.
 * Overview: Retorna el valor de entrada para un bit de un GPIO en especifico.
 * Input: Numero del GPIO
 * Output: Estado del GPIO.
 *
 *****************************************************************************/
uint8_t GPIO_GET_LEVEL(gpio_n_t gpio_num)
{
	uint_fast16_t inputPinValue;

	if(gpio_num < 31) /* GPIO 0-31 */
		inputPinValue = GPIO_GET_LEVEL_BIT(gpio_num) // LEE EL GPIO QUE INDICA EL VALOR DE ENTRADA DE UN PIN
	else	/* GPIO 32-39 */
		inputPinValue = GPIO_GET_LEVEL_BIT1(gpio_num) // LEE EL GPIO QUE INDICA EL VALOR DE ENTRADA DE UN PIN

	if (inputPinValue > 0)           // RETORNA EL VALOR 1 o 0
		return (0x01);
	return (0x00);
}
/*****************************************************************************
 * Function: GPIO_init_board
 * Preconditions: None.
 * Overview: Inicialización del m�dulo GPIO. Se configuran los pines de
 *          entrada y salida que corresponden a los LEDs y los switches
 *          en la tarjeta.
 * Input: None.
 * Output: None.
 *
 *****************************************************************************/
void GPIO_init_board(void)
{
    /* Para los led's de la tarjeta (7).*/
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED0)
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED1)
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED2)
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED3)
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED4)
	GPIO_ENABLE_OUTPUT_BIT(BSP_LED5)
	GPIO_CONFIG(BSP_LED6, GPIO_OUT);
	/* Apagamos los led's. */
	GPIO_SET_LEVEL(BSP_LED0, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED1, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED2, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED3, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED4, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED5, BSP_LED_L);
	GPIO_SET_LEVEL(BSP_LED6, BSP_LED_L);
	/* Para los botones de la tarjeta (2).*/
	GPIO_CONFIG(BSP_BTN1, GPIO_IN);
	GPIO_CONFIG(BSP_BTN2, GPIO_IN);
}
/*****************************************************************************
 * Function: LEDS_BLINK
 * Preconditions: None.
 * Overview: Parpadeo de los leds de la tarjeta
 * Input: None.
 * Output: None.
 *
 *****************************************************************************/
void LEDS_BLINK(void){
	GPIO_SET_LEVEL_TOGGLE(BSP_LED0)
	GPIO_SET_LEVEL_TOGGLE(BSP_LED1)
	GPIO_SET_LEVEL_TOGGLE(BSP_LED2)
	GPIO_SET_LEVEL_TOGGLE(BSP_LED3)
	GPIO_SET_LEVEL_TOGGLE(BSP_LED4)
	GPIO_SET_LEVEL_TOGGLE(BSP_LED5)
}
