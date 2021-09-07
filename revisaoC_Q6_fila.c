//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA
{
    NO *inicio;
    NO *fim;
}FILA;

void inicializar(FILA *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void queue(int dado, FILA *fila){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL){
        printf("Erro ao alocar");
    }else{
        ptr->dado = dado;
        ptr->prox = NULL;
        //Primeiro elemento da fila.
        if(fila->inicio == NULL){
            fila->inicio = ptr;
        }else{
            fila->fim->prox = ptr;
        }
        fila->fim = ptr;
    }
}

int dequeue(FILA *fila){
    NO *ptr = fila->inicio;
    int dado;
    if(ptr != NULL){
        fila->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if(fila->inicio == NULL){
            fila->fim = NULL;
        } 
        return dado;
    }else{
        printf("Fila Vazia");
        return;
    }
}

void imprimirFila(FILA *fila){
    NO *ptr = fila->inicio;
    if(ptr != NULL){
        while (ptr != NULL){
            printf("Dado: %d\n", ptr->dado);
            ptr = ptr->prox;
        }
    }else{
        printf("Vazio");
        return;
    }
}

int vazia(FILA *fila)
{
    NO *ptr = fila->inicio;
    if(ptr->prox == NULL)
        return 1;
    else
        return 0;
}

int verificarRepetidos(FILA *fila1, FILA *fila2){
    NO *ptr1 = fila1->inicio;
    NO *ptr2 = fila2->inicio;
    int qtd = 0;
    if(ptr1 != NULL){
        while (ptr1 != NULL){
            while(ptr2 != NULL){
                printf("Dado fila1: %d\n", ptr1->dado);
                printf("Dado fila2: %d\n", ptr2->dado);
                if (ptr2->dado == ptr1->dado){
                    qtd++;
                    printf("Entrou qtd atual: %d\n", qtd);
                }
                ptr2 = ptr2->prox;
            }
           ptr1 = ptr1->prox;
           ptr2 = fila2->inicio;
        }
    }else{
        return 0;
    }
    return qtd;
}


int main(){
    FILA *fila1 = (FILA*) malloc(sizeof(FILA));
    FILA *fila2 = (FILA*) malloc(sizeof(FILA));
    int qtd = 0;

    if(fila1 == NULL){
        printf("Erro ao alocar fila 1");
        exit(1);
    }else{
        inicializar(fila1);
        queue(1,fila1);
        queue(2,fila1);
        queue(8,fila1);
        imprimirFila(fila1);
    }

    printf("\n");

    if(fila2 == NULL){
        printf("Erro ao alocar fila 2");
        exit(1);
    }else{
        inicializar(fila2);
        queue(1,fila2);
        queue(6,fila2);
        queue(2,fila2);
        imprimirFila(fila2);
    }

    qtd = verificarRepetidos(fila1, fila2);

    printf("Quantidade repetida: %d\n",qtd);
    free(fila1);
    free(fila2);
    return 0;
}


