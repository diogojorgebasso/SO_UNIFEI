#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef int (*ptrFunc)(void);

typedef struct
{
  char *name;
  int time;
  int contador;
  ptrFunc func;
  int priority;
} process;

#define BUFFERSIZE 10
process buffer[BUFFERSIZE];

int start = 0, end = 0;

void addProc(process newProcess)
{
  if (((end + 1) % BUFFERSIZE) != start)
  {
    buffer[end].name = strdup(newProcess.name); // Cópia do nome
    buffer[end].time = newProcess.time;
    buffer[end].func = newProcess.func;
    buffer[end].contador = newProcess.contador;
    buffer[end].priority = newProcess.priority;
    end = (end + 1) % BUFFERSIZE;
  }
  else
  {
    printf("Buffer cheio, processo %s não adicionado.\n", newProcess.name);
  }
}

void execProc(void)
{
  buffer[start].func();
}

void removeProc(void)
{
  if (start != end)
  {
    int contador = buffer[start].contador;

    if (contador == 0)
    {
      free(buffer[start].name);
      start = (start + 1) % BUFFERSIZE;
    }
    else if (contador >= 1 && contador <= 14)
    {
      buffer[start].contador--;
      execProc();
      addProc(buffer[start]);
      start = (start + 1) % BUFFERSIZE;
      removeProc();
    }
    else if (contador == 15)
    {
      execProc();
      // Reagende o processo movendo-o para o final do buffer
      addProc(buffer[start]);
      start = (start + 1) % BUFFERSIZE;
      removeProc();
    }
  }
}

int func1(void)
{
  printf("Executando func1\n");
  return 0;
}
int func2(void)
{
  printf("Executando func2\n");
  return 0;
}
int func3(void)
{
  printf("Executando func3\n");
  return 0;
}

void order()
{
  process buffer2;
  for (int j = start; j != end; j = (j + 1) % BUFFERSIZE)
  {
    for (int h = (j + 1) % BUFFERSIZE; h = (j + 1) % BUFFERSIZE; h != end)
    {
      if (buffer[j].priority > buffer[h].priority)
      {
        buffer2 = buffer[j];
        buffer[j] = buffer[h];
        buffer[h] = buffer2;
      }
    }
  }
}

void main(void)
{
  process p1 = {"Processo 1", 1, 2, func1, 1};
  process p2 = {"Processo 2", 2, 3, func2, 2};
  process p3 = {"Processo 3", 3, 1, func3, 3};

  order();

  addProc(p1);
  addProc(p2);
  addProc(p3);

  removeProc();
  removeProc();
  removeProc();
}