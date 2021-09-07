//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct pilha {
    int n;
    int vet[MAX];
}Pilha;

Pilha* criaPilha ()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}

//Desempilha 
int pop (Pilha* p)
{
    int v;
    if (pilhaVazia(p)) {
    printf("Pilha vazia.\n");
    exit(1); /* aborta programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    printf("Numero desempilhado: %d\n", p->vet[p->n]);
    p->n--;
    return v;
}

//Empilha
void push (Pilha* p, int v){
    if (p->n == MAX) { /* capacidade esgotada */
    printf("Capacidade da pilha estourou.\n");
    exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;

    printf("Numero empilhado: %d\n", p->vet[p->n]);

    p->n++;
}

int pilhaVazia (Pilha* p)
{
    return (p->n == 0);
}

void liberaPilha (Pilha* p)
{
    free(p);
}

int maiorPilha(Pilha *p){
    int *aux;
    int *maior; 

    if (pilhaVazia(p)){
        maior = 0;  
        return maior;
    }

    aux = pop(p);
    maior = aux;

    while (!pilhaVazia(p))
    {
        aux = pop(p);
        printf("Aux: %d\n", aux);
        printf("Maior: %d\n", maior);

        if(aux > maior){
            maior = aux;
        }
    }

}

int main(){

    Pilha *pilha;
    pilha = criaPilha();

    for (size_t i = 0; i < MAX; i++)
    {
         push(pilha, i);
    }

    maiorPilha(pilha);
    
    for (int i = 0; i < MAX; i++)
    {
        printf("Rodando pilha: %d\n", pilha->vet[i]);
    }
    
    liberaPilha(pilha);
}
