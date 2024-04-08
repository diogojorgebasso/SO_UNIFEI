#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef void (*ptrFunc)(void);

typedef enum {
    READY,
    RUNNING,
    TERMINATED
} ProcessState;

typedef struct {
    int id;
    int priority;
    float time_left;
    int running;
    ProcessState state;
    ptrFunc func;
} Process;

Process processes[MAX_PROCESS];
int numProcesses = 0;
int currentProcessIndex = -1;
int start = 0;
int fin = 0;
int aux = 1;

void createProcess(int priority, float tempo, ptrFunc fPont) {
    if ((fin+1)%MAX_PROCESS != start) {
        fin = (fin+1)%MAX_PROCESS;
        Process newProcess;
        newProcess.id = numProcesses;
        newProcess.priority = priority;
        newProcess.time_left =  tempo;
        newProcess.state = READY;
        newProcess.func = fPont;
        processes[numProcesses++] = newProcess;
        printf("Process with ID %d created.\n", newProcess.id);
    } else {
        printf("Maximum number of processes reached.\n");
    }
}

void changePriority(int pid, int newPriority) {
    for (int i = start; i != fin; i++) {
        if (processes[i].id == pid) {
            processes[i].priority = newPriority;
            printf("Priority of process with PID %d changed to %d.\n", pid, newPriority);
            break;
        }
        i = i%MAX_PROCESS;
    }
}

void terminateProcess() {
    if (start != fin) {
        processes[start].func();
        processes[start].state = TERMINATED;
        printf("Process with ID %d terminated.\n", processes[start].id);
        start = (start+1)%MAX_PROCESS;
    }else{
        printf("vetor vazio \n");
    }
}

void schedule() {
    Process aux1;
    if(aux > 0){
        printf("\nPrioridade: \n");
        int highestPriority = -1;
        for (int i = start; i != fin; i++) {
            if (processes[i].state == READY && processes[i].priority > highestPriority) {
                aux1 = processes[start];
                processes[start] = processes[i];
                processes[i] = aux1;
                highestPriority = processes[start].priority;
            }
            i = i%MAX_PROCESS;
        }
        if (highestPriority != -1) {
            processes[start].state = RUNNING;
            printf("Process with ID %d is now running.\n", processes[start].id);
        } else {
            printf("No process to run.\n");
        }
        terminateProcess();
        aux = -1;
    }else{
        printf("\nTempo: \n");
        float lowestTemp = 20000000;
        for (int i = start; i != fin; i++) {
            if (processes[i].state == READY && processes[i].time_left < lowestTemp) {
                aux1 = processes[start];
                processes[start] = processes[i];
                processes[i] = aux1;
                lowestTemp = processes[start].time_left;
            }
            i = i%MAX_PROCESS;
        }
        if (lowestTemp != 20000000) {
            processes[start].state = RUNNING;
            printf("Process with ID %d is now running.\n", processes[start].id);
        } else {
            printf("No process to run.\n");
            currentProcessIndex = 20000000;
        }
        terminateProcess();
        aux = 1;
    }
}

void printProcessInfo() {
    printf("Current Process List:\n");
    for (int i = start; i != fin; i++) {
        printf("ID: %d | Priority: %d | time: %.02f | State: %d\n",
               processes[i].id, processes[i].priority,processes[i].time_left, processes[i].state);
        i = i%MAX_PROCESS;
    }
}
int main() {
    createProcess(3,1.5,printProcessInfo);
    createProcess(1,2.3,printProcessInfo);
    createProcess(5,3.2,printProcessInfo);
    createProcess(4,0.7,printProcessInfo);
    createProcess(2,2.7,printProcessInfo);

    schedule();
    printf("\n");
    schedule();
    printf("\n");
    schedule();
    printf("\n");
    schedule();
    printf("\n");
    schedule();
    return 0;
}
