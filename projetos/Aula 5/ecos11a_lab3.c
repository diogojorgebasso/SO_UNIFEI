#include <stdio.h>
#define MAX_SIZE 10
#define SUCESS
#define REPEAT
#define FAIL

int contador_funcao = 0;

typedef void (*pointerTest)(void);

typedef struct {
    char * ProcessName;
    int Time;
    pointerTest func;
} PID_process;

PID_process buffer[MAX_SIZE];

int head = 0, tail = 0, size = 0;

void AddProc(char * ProcessName, int Time, void *function) {
    if (size == MAX_SIZE) {
        printf("Buffer is full\n");
        return;
    }
    buffer[tail].ProcessName = ProcessName;
    buffer[tail].Time = Time;
    buffer[tail].func = function;
    tail = (tail+1) % MAX_SIZE;
    size++;
}

PID_process RemoveProc() {
  if (size == 0) {
    printf("Buffer is empty\n");
  }
  PID_process element = buffer[head];
  head = (head + 1) % MAX_SIZE;
  size--;
  return element;
}

void print_buffer() {
  if (size == 0) {    ExeProc();

    printf("Buffer is empty\n");
    return;
  }
  printf("Buffer contents: \n");
  for (int i = 0; i < size; i++) {
    int index = (head + i) % MAX_SIZE;
    printf("Processo %s tempo %d \n", buffer[index].ProcessName, buffer[index].Time);
  }
  printf("\n");
}

void ExeProc(){
    PID_process element = buffer[head];
    element.func();
}

void func1(){
    printf("Eu me chamo Diogo - Processo %s \n", buffer[head].ProcessName);
    return SUCESS;
}

void func2(){
    printf("Eu me chamo Anderson - Processo %s \n", buffer[head].ProcessName);
    return SUCESS;
}

void func3(){
    printf("Eu me chamo Joao - Processo %s \n", buffer[head].ProcessName);
    return REPEAT;
}

void func4(){
    printf("Eu me chamo Luiz - Processo %s \n", buffer[head].ProcessName);
    contador_funcao++;
    printf("Vezes: %d \n",contador_funcao);
    return REPEAT;
}

int main() {
    AddProc("name1", 1, func1);
    AddProc("name2", 2, func2);
    AddProc("name3", 3, func3);
    AddProc("name4", 4, func4);
    ExeProc();
    RemoveProc();
    ExeProc();
    RemoveProc();
    ExeProc();
    RemoveProc();
    ExeProc();
    ExeProc();
    RemoveProc();
    return 0;
}
