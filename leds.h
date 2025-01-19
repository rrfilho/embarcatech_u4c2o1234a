#include "pico/stdlib.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13

void init_leds(void){
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
}

void set_led_array(bool turn_on_green, bool turn_on_blue, bool turn_on_red) {
  gpio_put(LED_GREEN, turn_on_green);
  gpio_put(LED_BLUE, turn_on_blue);
  gpio_put(LED_RED, turn_on_red);
}

void leds_for_key(char keypad_key){
    switch(keypad_key){
        case '1': set_led_array(false, false, true); break;
        case '2': set_led_array(false, true, false); break;
        case '3': set_led_array(true, false, false); break;
        case '4': set_led_array(false, true, true); break;
        case '5': set_led_array(true, false, true); break;
        case '6': set_led_array(false, true, true); break;
        case '7': set_led_array(true, true, true); break;
        default: set_led_array(false, false, false);
    }    
}