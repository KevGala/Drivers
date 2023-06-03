/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "GPIO2023.h"

#define BLINK_GPIO 15
#define GPIO_I 34

int s_led_state = 0;


static void blink_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
	GPIO_SET_LEVEL(BLINK_GPIO, s_led_state);
}

void app_main(void)
{
	GPIO_init_board();

	while (1) {
		blink_led();
		s_led_state = ~s_led_state;

		printf("BTN = %d\n", GPIO_GET_LEVEL(GPIO_I));

		vTaskDelay(500 / 10);
	}
}
