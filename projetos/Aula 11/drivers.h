#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdio.h> // Necessário para as funções de saída, como printf
#include <stdlib.h>

typedef void (*ptrFunc)(void *);
typedef struct driver *(*ptrGetDrv)(void);

// Estrutura de um driver
typedef struct driver
{
  char id;
  ptrFunc initFunc;
  ptrFunc *funcoes;
  int contador;
} driver;

// Protótipos das funções do controlador de drivers
char initCtrDrv(void);
char initDriver(char newDriver);
char callDriver(char drv_id, char func_id, void *parameters);

#endif // DRIVERS_H