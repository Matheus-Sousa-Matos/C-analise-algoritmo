//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

#define TAM 4

int main(){
    int *vetor;

    vetor = (int*)malloc(TAM*sizeof(int));

    for (int i = 0; i < TAM; i++)
    {
        vetor[i] = i;
    }

    //soma do vetor recursivo
    int resultado = somarVetor(vetor, 0);

    printf("Resultado: %d", resultado);
}

int somarVetor(int *vetor, int i){

    if (i < TAM){
        return vetor[i] + somarVetor(vetor, i+1);
    }
    else{
        return 0;
    }

}