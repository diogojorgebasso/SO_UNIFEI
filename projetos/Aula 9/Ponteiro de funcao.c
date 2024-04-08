#include <stdio.h>

void funcao(int *a, int *b)
{
  *a = *a + *b;
}

int main()
{
  int a;
  int b;
  printf("Escreva o valor de a: ");
  scanf("%d", &a);
  printf("Escreva o valor de b: ");
  scanf("%d", &b);

  printf("A: ");
  printf("%d \n", a);
  printf("B: ");
  printf("%d \n", b);

  funcao(&a, &b);
  printf("A: %d\n", a);
  printf("B: %d \n", b);
}