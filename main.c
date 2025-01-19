#include <stdio.h>
#include "keypad.h"
#include "buzzer.h"
#include "leds.h"

int main() {
    stdio_init_all();
    init_keypad();
    init_buzzer();
    init_leds();

    while (true) {
        char key = read_keypad();
        if (key != '\0') {
            printf("%c foi pressionado.\n", key);
            leds_for_key(key);
            buzzee_for_key(key);
        }
        sleep_ms(50);
    }   
}