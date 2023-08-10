#include <stdio.h>

// tem-se que usar ponteiros para modificar o valor de a
void somar(int *a, int b)
{
  *a = *a + b;
}

int main()
{
  int a = 10;
  int b = 20;
  printf("a = %d, b = %d\n", a, b);
  somar(&a, b);
  printf("a = %d, b = %d\n", a, b);
  return 0;
}