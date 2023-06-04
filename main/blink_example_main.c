/*****************************************************
 * FileName:        blink_example_main.C
 * Dependencies:	GPIO2023.h, freertos/FreeRTOS.h, freertos/task.h
 * Processor:       ESP32
 * Board:           ESP32
 * Program version: ECLIPSE IDE
 * Company:         TecNM /IT Chihuahua
 * Description:     Ejemplo de parpadeo de un LED y la lectura de un boton.
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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "GPIO2023.h"

#define BLINK_GPIO 15
#define GPIO_I     34
int s_led_state = 0;

static void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
	GPIO_SET_LEVEL(BLINK_GPIO, s_led_state);
}

void app_main(void)
{
	GPIO_CONFIG(BLINK_GPIO, GPIO_OUT);
	GPIO_CONFIG(GPIO_I, GPIO_IN);

	while (1) {
		blink_led();
		s_led_state = ~s_led_state;

		printf("BTN_I = %d\n", GPIO_GET_LEVEL(GPIO_I));

		vTaskDelay(500 / 10);
	}
}
