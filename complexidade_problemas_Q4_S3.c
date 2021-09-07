//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[5] = {1,4,6,2,3};
    int k = 2;
    int tam = 5;

    int menor = kesimo(v,k,tam);
    printf("MENOR: %d", menor);
}

int kesimo(int *v, int tam, int k){
    int tiraMenor;
    for (int i = 0; i < k; i++)
    {
        tiraMenor = tMenor(v,tam);
    }
    return tiraMenor;
}

int tMenor(int *v,int *tam){
    int menor = __INT32_MAX__, pos = -1;

    for (int i = 0; i < tam; i++)
    {
        if(v[i] < menor){
            menor = v[i];
            pos = i;
        }
    }
    v[pos] = __INT32_MAX__;
    return menor;
}