#ifndef BUZZER_H
#define BUZZER_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define BUZZER 21

// Inicializa o buzzer
void start_buzzer() {
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);  // Pino PWM para alterar TONE do Buzzer
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_config config = pwm_get_default_config();
    pwm_init(slice_num, &config, true);  // Inicializa o PWM no slice
    pwm_set_gpio_level(BUZZER, 0);   // Desliga buzzer
}

// Ativa o buzzer na tecla pressionada
void ativa_buzzer(char key) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint freq = 0;  
    
   
    switch (key) {
        case 'A': freq = 2500; break;
        case 'B': freq = 5000; break;
        case 'C': freq = 7500; break;
        case 'D': freq = 10000; break;
        default: return;  // Tecla invalida
    }
    
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (freq * 4096));
    pwm_init(slice_num, &config, true);  
    pwm_set_gpio_level(BUZZER, 32768);  
    sleep_ms(500); 
    pwm_set_gpio_level(BUZZER, 0);  
}

#endif
