#include <stdio.h>

void changeValue(int x)
{
  // o valor de x é copiado para a variável local x
  x = 10;
}
int main()
{
  int num = 5;
  changeValue(num);
  printf("%d\n", num);
  return 0;
}