//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int acimaMedia(int tam, int *vetor);

int main(){

    int vetor[] = {1,2,3,4,5};
    int tam = sizeof(vetor)/sizeof(vetor[0]);
    int *novoVetor;

    for (int i = 0; i < tam; i++)
    {
        printf("Vetor posicao[%d] = %d\n",i,vetor[i]);
    }
    
    novoVetor = acimaMedia(tam, vetor);
    int tamNovoVetor = sizeof(novoVetor)/sizeof(novoVetor[0]);

    for (int i = 0; i <= tamNovoVetor; i++)
    {
        printf("Novo vetor[%d]: %d\n",i,novoVetor[i]);
    }
}

int acimaMedia(int tam, int *vetor){
    float soma = 0, media = 0;
    int *novoVetor;
    int tamNovoVetor = 0;
    int pos = 0;

    for (int i = 0; i < tam; i++)
    {
        soma = soma + vetor[i];
    }

    media = soma/tam;

    for (int j = 0; j < tam; j++)
    {
        if(vetor[j] > media){
            tamNovoVetor += 1;
        }
    }

    //Alocando dinamicamente o novo vetor
    novoVetor = (int *) malloc(tamNovoVetor*sizeof(int));

    for (int j = 0; j < tam; j++)
    {
        if(vetor[j] > media){
            novoVetor[pos] = vetor[j];
            pos++;
        }
    }

    return novoVetor;

}