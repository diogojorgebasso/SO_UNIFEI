#include "stdio.h"

typedef struct
{
  char *processName;
  int time;
} process;

#define BUFFERSIZE 4
process buffer[BUFFERSIZE];

int start = 0, end = 0;

void addProc(char *nname, int ntime)
{
  if (isBufferFull())
  {
    printf("Buffer cheio");
  }
  // Se estiver cheio
  else
  {
    printf("Adicionado.");
    buffer[end].processName = nname;
    buffer[end].time = ntime;
    end = (end + 1) % (BUFFERSIZE);
  }
}

void removeProc(void)
{

  if (end != start)
  {
    // incremente
    start = (start + 1) % (BUFFERSIZE);
  }
}

int isBufferFull(void)
{
  return ((end + 1) % BUFFERSIZE) == start;
}

int isBufferEmpty(void)
{
  return end == start;
}

// Function to print buffer details
void printBuffer(void)
{
  int i = start;
  printf("\nBuffer details:\n");
  while (i != end)
  {
    printf("Process name: %s, Time: %d\n", buffer[i].processName, buffer[i].time);
    i = (i + 1) % BUFFERSIZE;
  }
  printf("Start position: %d, End position: %d\n", start, end);
}

void main(void)
{
  addProc("proc1", 0);
  addProc("proc2", 1);
  addProc("proc3", 2);
  addProc("proc4", 3);
  isBufferFull();
  isBufferEmpty();
  printBuffer();
  removeProc();
  removeProc();
  removeProc();
}
