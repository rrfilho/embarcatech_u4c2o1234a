#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define BUZZER 21

void init_buzzer() {
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);  // Pino PWM para alterar TONE do Buzzer
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_config config = pwm_get_default_config();
    pwm_init(slice_num, &config, true);  // Inicializa o PWM no slice
    pwm_set_gpio_level(BUZZER, 0);   // Desliga buzzer
}

void buzzee_for_key(char key) {
    uint freq;  
    switch (key) {
        case '0': freq = 2000; break;
        case '1': freq = 2500; break;
        case '2': freq = 3000; break;
        case '3': freq = 3500; break;
        case '4': freq = 4000; break;
        case '5': freq = 4500; break;
        case '6': freq = 5000; break;
        case '7': freq = 5500; break;
        case '8': freq = 6000; break;
        case '9': freq = 6500; break;
        case 'A': freq = 7000; break;
        case 'B': freq = 7500; break;
        case 'C': freq = 8000; break;
        case 'D': freq = 8500; break;
        case '*': freq = 9000; break;
        case '#': freq = 9500; break;
    }
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (freq * 4096));
    pwm_init(slice_num, &config, true);  
    pwm_set_gpio_level(BUZZER, 32768);  
    sleep_ms(500); 
    pwm_set_gpio_level(BUZZER, 0);  
}