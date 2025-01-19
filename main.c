#include "pico/stdlib.h"
#include "buzzer.h"
#include "keypad.h"

int main(){
  start_gpio();  // Inicializa os pinos do teclado

  while(true){
    char key = keypad_leitura();  // Lê a tecla pressionada
    if(key){
       teclado_opcao(key);  // Chama a função do buzzer com base na tecla pressionada
    }
    sleep_ms(1000);  // Espera 1 segundo antes de verificar a próxima tecla
  }
  return 0;
}
