//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){

    int v[TAM]= {1,2,3,4,5,6,7,8,9,10};
    
    soma(v);

}

void soma(int v[TAM]){
    int somatoria = NULL;

     for (int i = 0; i < TAM; i++)
    { 
        somatoria = somatoria + v[i];
    } 
    printf("somatoria: %d", somatoria);
}