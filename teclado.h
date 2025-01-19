#include <stdio.h>
#include "pico/stdlib.h"



#define linhas 4
#define cols 4

const uint cols_PINS[cols] = {4, 3, 2, 1};  // Colunas: C1, C2, C3, C4   
const uint linhas_PINS[linhas] = {8, 7, 6, 5};  // Linhas: R1, R2, R3, R4

// Mapa do teclado
const char keypad[linhas][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


// Inicializar os pinos do teclado
void keypad_init() {
  
  for (int i = 0; i < 4; i++)
  {
    gpio_init(linhas_PINS[i]);
    gpio_set_dir(linhas_PINS[i], GPIO_OUT);
    gpio_put(linhas_PINS[i], 0); // linhas como saida em nivel baixo 0
    
  }

  // Configuração das colunas do teclado
  for (int i = 0; i < 4; i++)
  {
    gpio_init(cols_PINS[i]);
    gpio_set_dir(cols_PINS[i], GPIO_OUT);
    gpio_pull_down(cols_PINS[i]); // entradas com pull up valor 0
  }
}

// Para ler o teclado 
char ler_keypad()
{
  for (int i = 0; i < 4; i++)
  {
    gpio_put(linhas_PINS[i], 1); // Ativa a linha colocando em 1
    for (int j = 0; j < 4; j++){
      if (gpio_get(cols_PINS[j])) // se cols_PINS estiver em nivel 1
      {
        
        return keypad[i][j];    // Retorna a tecla pressionada
        
      }
    }
    gpio_put(linhas_PINS[i], 0); // retorna a linha para 0
    
  }
  
  return '\0'; // Retorno nulo, nenhuma tecla pressionada
}



void teclado() {

  stdio_init_all();

  keypad_init();

  printf("A leitura do teclado foi iniciada\n");

  while (true) {
      char key = ler_keypad();
      if (key != '\0') // verifica se uma tecla foi pressionada
      { 
      printf("A tecla pressionada foi: %c \n", key);
      sleep_ms(300); // Debounce delay
    }

}

}
