#include "pico/stdlib.h"

#define LINHAS 4
#define COLS 4

const uint cols_pins[COLS] = {4, 3, 2, 1};  // Colunas: C1, C2, C3, C4   
const uint linhas_pins[LINHAS] = {8, 7, 6, 5};  // Linhas: R1, R2, R3, R4

// Mapa do teclado
const char keypad[LINHAS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void init_keypad() {
  // Configuração das colunas do teclado
  for (int i = 0; i < COLS; i++) {
    gpio_init(cols_pins[i]);
    gpio_set_dir(cols_pins[i], GPIO_OUT);
    gpio_put(cols_pins[i], 0); // linhas como saida em nivel baixo 0
  }
  // Configuração das linhas do teclado
  for (int i = 0; i < LINHAS; i++) {
    gpio_init(linhas_pins[i]);
    gpio_set_dir(linhas_pins[i], GPIO_IN);
    gpio_pull_down(linhas_pins[i]); // entradas com pull down
  }
}
 
char read_keypad() {
  for (int i = 0; i < LINHAS; i++) {
    gpio_put(cols_pins[i], 1); // Ativa a linha colocando em 1
    for (int j = 0; j < COLS; j++) {
      if (gpio_get(linhas_pins[j])) { // se cols_pins estiver em nivel 1
        gpio_put(cols_pins[i], 0); 
        return keypad[j][i];    // Retorna a tecla pressionada
      }
    }
    gpio_put(cols_pins[i], 0); // retorna a linha para 0
  }
  return '\0'; // Retorno nulo, nenhuma tecla pressionada
}