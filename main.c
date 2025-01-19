#include <stdio.h>
#include "pico/stdlib.h"
#include "LEDS.h"


int main()
{
    stdio_init_all();
    init_led();
    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
