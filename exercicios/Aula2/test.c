#include <stdio.h>

#define BUFFER_SIZE 10

float buffer[BUFFER_SIZE];
float *inserir_ptr = buffer;
float *remover_ptr = buffer;

void inserir_dado(float dado)
{
  *inserir_ptr = dado;
  inserir_ptr++;
  if (inserir_ptr == buffer + BUFFER_SIZE)
  {
    inserir_ptr = buffer;
  }
}

float remover_dado(void)
{
  float dado = *remover_ptr;
  remover_ptr++;
  if (remover_ptr == buffer + BUFFER_SIZE)
  {
    remover_ptr = buffer;
  }
  return dado;
}

int buffer_cheio(void)
{
  return (inserir_ptr + 1 == remover_ptr) ||
         (inserir_ptr == buffer + BUFFER_SIZE - 1 && remover_ptr == buffer);
}

int buffer_vazio(void)
{
  return inserir_ptr == remover_ptr;
}

int main(void)
{
  // Inserir 10 elementos no buffer
  for (float i = 0.1f; i <= 1.0f; i += 0.1f)
  {
    inserir_dado(i);
  }

  // Remover e imprimir 10 elementos do buffer
  for (int i = 0; i < 10; i++)
  {
    float dado = remover_dado();
    printf("Dado removido: %.1f\n", dado);
  }

  return 0;
}