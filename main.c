#include "pico/stdlib.h"
#include "buzzer.h"

int main() {
    start_buzzer(); 

    while (true) {
        char key = keypad_leitura();  // Lê a tecla pressionada do teclado ==== FUNÇÃO Keypad_leitura() apagada
        if (key) {
            ativa_buzzer(key);  // Ativa o buzzer na tecla pressionada
        }
        sleep_ms(1000);  
    }

    return 0;
}
