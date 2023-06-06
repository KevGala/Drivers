# Drivers

| Tarjeta soportada | ESP32 | 
| ----------------- | ----- | 

# Ejemplo parpadeo de un LED y lectura de un GPIO

Este ejemplo funciona para hacer el parpadeo de un led y la lectura del estado de un GPIO. Esto haciendo uso de los drivers creados, de los cuales puedes hacer uso simplemente copiando la carpeta de componentes en tus proyectos o usando este proyecto y modificando. El componente BSP es usado para tener una estructura de los pines de la esp32, además de tener algunas definiciones para el uso de una tarjeta específica. Y por último el componente GPIO2023 es el que cuenta con todas las funciones que se presentarán a continuación. 


## Función para configurar GPIO
* GPIO_CONFIG(gpio_n_t gpio_num,  uint8_t e);     

Recibe el número del GPIO a configurar y un valor de tipo entero, 1 para configurar como salida y 0 para configurar como entrada. No regresa nada.

## Función que establece un valor en un GPIO de salida
* GPIO_SET_LEVEL(gpio_n_t gpio_num, uint8_t level);  

Recibe el número del GPIO y el estado que se quiere poner alto o bajo. No regresa nada.

## Función que retorna el valor de entrada de un GPIO
* GPIO_GET_LEVEL(gpio_n_t gpio_num);  

Función para leer un GPIO. Recibe el número del GPIO y retorna el valor leído.

## Función que inicializa el módulo GPIO
* GPIO_init_board(void);  

Función para inicializar la tarjeta con algunos valores específicos de una tarjeta, no hace falta usarla. No recibe ni regresa nada.

## Función de parpadeo de todos los LEDS
* LEDS_BLINK();  

Función para hacer el parpadeo de LEDS  (GPIO_N_18, GPIO_N_5, GPIO_N_17, GPIO_N_16, GPIO_N_4, GPIO_N_2 Y GPIO_N_15).  No recibe ni regresa nada.
