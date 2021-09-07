//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){

    int v[TAM]= {2,9,4,5,7,8,0,11,21,15};
    
    verificaMaior(v);

}

void verificaMaior(int v[TAM]){
    int maior = NULL;

     for (int i = 0; i < TAM; i++)
    {
        if (v[i] > maior)
         {
            maior = v[i];
         }
    } 
    printf("Maior: %d", maior);
}