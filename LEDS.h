#include "pico/stdlib.h"
#include "hardware/timer.h"
#ifndef LEDS_H
#define LEDS_H

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13

void init_led(void){
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
}
//acender os leds passar o parametro tipo char
void acender_led(char keypad_key){
    switch(keypad_key){
        case '1': gpio_put(LED_RED, true); break;
        case '2': gpio_put(LED_BLUE, true); break;
        case '3': gpio_put(LED_GREEN,true); break;
        case '4': gpio_put(LED_RED, true); gpio_put(LED_BLUE, true); break;
        case '5': gpio_put(LED_RED, true); gpio_put(LED_GREEN,true); break;
        case '6': gpio_put(LED_BLUE, true); gpio_put(LED_GREEN,true); break;
        case '7': gpio_put(LED_RED, true); gpio_put(LED_BLUE, true); gpio_put(LED_GREEN,true); break;
    }    
}

#endif

