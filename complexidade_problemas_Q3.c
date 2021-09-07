//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main(){

    int matriz[TAM][TAM] = {2,9,4,5};
    
    verificaMaior(matriz);

}

void verificaMaior(int matriz[TAM][TAM]){
    int maior = NULL;

     for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (matriz[i][j] > maior)
            {
               maior = matriz[i][j];
            }
        }
    } 
    printf("Maior: %d", maior);
}