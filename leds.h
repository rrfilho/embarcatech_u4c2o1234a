#include "pico/stdlib.h"

static const uint GREEN_LED_PIN = 11;
static const uint BLUE_LED_PIN = 12;
static const uint RED_LED_PIN = 13;

static void init_led(uint led_pin) {
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);
}

void init_leds() {
  init_led(GREEN_LED_PIN);
  init_led(BLUE_LED_PIN);
  init_led(RED_LED_PIN);
}

void set_led_array(bool turn_on_green, bool turn_on_blue, bool turn_on_red) {
  gpio_put(GREEN_LED_PIN, turn_on_green ? 1 : 0);
  gpio_put(BLUE_LED_PIN, turn_on_blue ? 1 : 0);
  gpio_put(RED_LED_PIN, turn_on_red ? 1 : 0);
}

static void leds_for_key(char key) {
    switch(key) {
        case '1': set_led_array(true, false, false); break;
        case '2': set_led_array(false, true, false); break;
        case '3': set_led_array(false, false, true); break;
        case '4': set_led_array(true, true, false); break;
        case '5': set_led_array(true, false, true); break;
        case '6': set_led_array(false, true, true); break;
        case '7': set_led_array(true, true, true); break;
        default: set_led_array(false, false, false);
    }
}