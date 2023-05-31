/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "GPIO2023.h"

#define BLINK_GPIO BSP_LED0

static uint8_t s_led_state = 0;


static void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
	GPIO_SET_LEVEL(BLINK_GPIO, s_led_state);
}

void app_main(void)
{
	GPIO_init_board();

	GPIO_CONFIG(GPIO_N_14, GPIO_IN);

	while (true) {
		blink_led();

		s_led_state = ~s_led_state;

		GPIO_SET_LEVEL(BSP_LED4, GPIO_GET_LEVEL(GPIO_N_14) );

		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}
