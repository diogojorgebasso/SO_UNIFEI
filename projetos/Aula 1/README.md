# Laboratório de Sistemas Operacionais (ECOS11A)

IESTI - Instituto de Engenharia de Sistemas e Tecnologia da Informação

Prof Otávio Gomes (otavio.gomes@unifei.edu.br)

## Revisão de Estruturas de Dados

### 1. Qual será o valor impresso após a execução do código abaixo?

```cpp
   #include <stdio.h>
   void modifyArray(int arr[]) {
   arr[0] = 100;
   }
   int main() {
   int nums[] = {10, 20, 30};
   modifyArray(nums);
   printf("%d\n", nums[0]);
   return 0;
   }

```

Resposta: 100

### 2. Qual é o algoritmo de ordenação utilizado no seguinte trecho de código?

```cpp
#include <stdio.h>
void selectionSort(int arr[], int size) {
// Algoritmo de ordenação ocorreria aqui
}
int main() {
int nums[] = {5, 2, 8, 1, 3};
int size = sizeof(nums) / sizeof(nums[0]);
selectionSort(nums, size);
return 0;
}
```

Resposta: Qualquer algoritmo de ordenação pode ser utilizado. Um exemplo está listado na pasta `/projetos/Aula 1/ex2.c`

### 3. Qual é a saída deste código?

```cpp
   #include <stdio.h>
   void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
   printf("%d ", arr[i]);
   }
   printf("\n");
   }
   int main() {
   int nums[] = {4, 1, 7, 3, 9};
   int size = sizeof(nums) / sizeof(nums[0]);
   printArray(nums, size);
   return 0;
   }
```

Resposta: 4 1 7 3 9

### 4. Qual será o valor após a execução deste código?

```cpp
#include <stdio.h>
int computeSum(int arr[], int size) {
int sum = 0;
for (int i = 0; i < size; i++) {
sum += arr[i];
}
return sum;
}
int main() {
int nums[] = {2, 4, 6, 8, 10};
int size = sizeof(nums) / sizeof(nums[0]);
int result = computeSum(nums, size);
printf("%d\n", result);
return 0;
}
```

Resposta: 30

### 5. Qual é a saída esperada deste código?

```cpp
#include <stdio.h>
void changeValue(int x) { x = 10; }
int main() {
int num = 5;
changeValue(num);
printf("%d\n", num);
return 0;
}
```

Resposta: 5

### 6. Qual será o valor de resultado após a execução deste código?

```cpp
#include <stdio.h>
int findMax(int arr[], int size) {
int max = arr[0];
for (int i = 1; i < size; i++) {
if (arr[i] > max) {
max = arr[i];
}
} return max;
}
int main() {
int nums[] = {22, 7, 15, 43, 30};
int size = sizeof(nums) / sizeof(nums[0]);
int result = findMax(nums, size);
printf("%d\n", result);
return 0;
}
```

Resposta: 43

### 7. O que o seguinte código faz?

```cpp
   #include <stdio.h>
   void reverseArray(int arr[], int size) {
   for (int i = 0; i < size / 2; i++) {
   int temp = arr[i];
   arr[i] = arr[size - 1 - i];
   arr[size - 1 - i] = temp;
   }
   }


int main() {
int nums[] = {1, 2, 3, 4, 5};
int size = sizeof(nums) / sizeof(nums[0]);
reverseArray(nums, size);

for (int i = 0; i < size; i++) {
printf("%d ", nums[i]);
}

return 0;
}
```

Resposta: Inverte a ordem dos elementos do vetor

### 8. Criação de um programa em C

Faça um programa em linguagem C que crie e leia um vetor de 5 estruturas de dados (struct/registro) com: código(máximo 40 letras), duração(int), prioridade(int) e seção.
A seção deve ser outra estrutura de dados contendo ponteiro(char), dados (máximo 64 letras) e pilha (máximo 64 letras).

### 9. Criação de um programa em C

Crie um programa que contenha uma função que permita passar por parâmetro dois números inteiros A e B. A função deverá calcular a soma entre estes dois números e armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro parâmetro.
Antes e após a execução da função imprima os valores de A e B na função principal.

### 10. Leia o trecho de código a seguir e identifique sua função:

```cpp
void selection_sort(int num[], int tam){
int i, j, min, swap;
for (i = 0; i < (tam-1); i++){
min = i;
for (j = (i+1); j < tam; j++)
if(num[j] > num[min])
min = j;
if (i != min) {
swap = num[i];
num[i] = num[min];
num[min] = swap;
}
}
}
```

a) Escreva uma função para ordenar uma fila em ordem crescente de seus
valores (prioridade).

b) Suponha que n tarefas devem ser processadas em um único processador.
Dadas as durações t_1 até t_n das tarefas (int), em que ordem elas devem ser
processadas para minimizar o tempo médio de conclusão de uma tarefa?
Desenvolva um programa em linguagem C que resolva este problema de
escalonamento de tarefas.

c) Escreva uma função que receba uma fila como argumento e retorne o valor
armazenado em seu início. A função deve remover também esse elemento.
