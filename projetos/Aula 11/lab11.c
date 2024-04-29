#include <stdio.h>
#include <stdlib.h>
#include "drivers.h"

#define QNTD_DRV 20
#define DRV_FUNC_NOT_FOUND -1
#define SUCCESS 0
#define FAIL -1
#define RETURN 2

static driver *drivers[QNTD_DRV];
static char dLoaded = 0;

// Implementações dos drivers
void initGenericoDriver(void *param) { printf("Inicializando Driver Generico\n"); }
void initInterruptDriver(void *param) { printf("Inicializando Driver de Interrupcao\n"); }
void initTimerDriver(void *param) { printf("Inicializando Driver de Timer\n"); }
void xpto(void *param) { printf("Inicializando Diogo\n"); }
void xpto1(void *param) { printf("Inicializando Diogo Lindo\n"); }
void xpto2(void *param) { printf("Inicializando Diogo Maravilhoso\n"); }

ptrFunc genFuncs[] = {initGenericoDriver, xpto, xpto1, xpto2};
ptrFunc intFuncs[] = {initInterruptDriver};
ptrFunc timFuncs[] = {initTimerDriver};

struct driver *getGenericoDriver(void)
{
  static struct driver genDriver = {.id = 0, .initFunc = initGenericoDriver, .funcoes = genFuncs, .contador = (sizeof(genFuncs) / sizeof(ptrFunc))};
  return &genDriver;
}

struct driver *getInterruptDriver(void)
{
  static struct driver intDriver = {.id = 1, .initFunc = initInterruptDriver, .funcoes = intFuncs, .contador = (sizeof(intFuncs) / sizeof(ptrFunc))};
  return &intDriver;
}

struct driver *getTimerDriver(void)
{
  static struct driver timeDriver = {.id = 2, .initFunc = initTimerDriver, .funcoes = timFuncs, .contador = (sizeof(timFuncs) / sizeof(ptrFunc))};
  return &timeDriver;
}

// Funções do controlador de drivers
char initCtrDrv(void)
{
  dLoaded = 0;
  return SUCCESS;
}

char initDriver(char newDriver)
{
  char resp = FAIL;

  if (dLoaded < QNTD_DRV)
  {

    switch (newDriver)
    {
    case 0:
      drivers[dLoaded] = getGenericoDriver();
      break;
    case 1:
      drivers[dLoaded] = getInterruptDriver();
      break;
    case 2:
      drivers[dLoaded] = getTimerDriver();
      break;
    default:
      return FAIL;
    }

    resp = SUCCESS;
    dLoaded++;
  }
  return resp;
}

char callDriver(char drv_id, char func_id, void *parameters)
{

  for (char i = 0; i < dLoaded; i++)
  {
    if (drv_id == drivers[i]->id && func_id < drivers[i]->contador)
    {
      drivers[i]->funcoes[func_id](parameters);
      return SUCCESS;
    }
  }
  return DRV_FUNC_NOT_FOUND;
}

// Main function
int main(void)
{
  initCtrDrv();
  initDriver(0); // Genérico
  initDriver(1); // Interrupção
  initDriver(2); // Timer

  // Chamadas de teste

  for (int i = 0; i < dLoaded; i++)
  {
    for (int j = 0; j < drivers[i]->contador; j++)
    {
      callDriver(i, j, NULL);
    }
  }

  return 0;
}
