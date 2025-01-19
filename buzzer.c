#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Função para definir a frequência do buzzer
void buzzer_frequencia(uint pin, uint frequencia) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    gpio_set_function(pin, GPIO_FUNC_PWM);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequencia * 4096));
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);
}

// Função para iniciar o buzzer com frequência e duração específicas
void init_buzzer(uint pin, uint frequencia, uint duracao) {
    buzzer_frequencia(pin, frequencia);
    pwm_set_gpio_level(pin, 32768);  // Aciona o buzzer
    sleep_ms(duracao);  // Espera a duração do som
    pwm_set_gpio_level(pin, 0);  // Desliga o buzzer após a duração
}

// Função para determinar qual ação tomar com base na tecla pressionada
void teclado_opcao(char key){
  if(key == 'A'){
    init_buzzer(21, 2500, 500);  // Frequência de 2500Hz e duração de 500ms
  }
  else if(key == 'B'){
    init_buzzer(buzzer, 5000, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 1000, 500);
  }
  else if(key == 'C'){
    init_buzzer(buzzer, 7500, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 5000, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 1000, 500);
  }
  else if(key == 'D'){
    init_buzzer(buzzer, 10000, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 8000, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 4000, 500);
    sleep_ms(100);
    init_buzzer(buzzer, 1000, 500);
  }
}
