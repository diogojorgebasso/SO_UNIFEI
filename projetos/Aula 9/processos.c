#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char ponteiro;
  char dados[64];
  char pilha[64];
} secao;

typedef struct
{
  char codigo[40];
  int duracao;
  int prioridade;
  secao secao;
} dado;

int main()
{
  dado processos[5];

  for (int i = 0; i < 5; i++)
  {
    printf("Digite o codigo\n");
    scanf("%s", &processos[i].codigo);
    printf("Digite a duracao\n");
    scanf("%d", &processos[i].duracao);
    printf("Digite a prioridade\n");
    scanf("%d", &processos[i].prioridade);
    printf("Digite o ponteiro da secao\n");
    scanf("%s", &processos[i].secao.ponteiro);
    printf("Digite os dados da secao\n");
    scanf("%s", &processos[i].secao.dados);
    printf("Digite a pilha da secao\n");
    scanf("%s", &processos[i].secao.pilha);
  }

  printf("\nDados dos processos:\n");

  for (int i = 0; i < 5; i++)
  {

    printf("\nCodigo: %s", processos[i].codigo);

    printf("\nDuracao: %d", processos[i].duracao);

    printf("\nPrioridade: %d", processos[i].prioridade);

    printf("\nSecao \n---\nPonteiro: %c", processos[i].secao.ponteiro);

    printf("\nDados: %s", processos[i].secao.dados);

    printf("\nPilha: %s", processos[i].secao.pilha);
  }

  return 0;
}