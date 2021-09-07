//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz1[2][2] = {2,4,6,8};
    int matriz2[2][2] = {1,2,3,4};
    
    /*
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Matriz_1[%d][%d]: %d\n", i,j,matriz1[i][j]);
        }
        
    } 
    */   

    multiplicaMatrizes(matriz1, matriz2);



}

void multiplicaMatrizes(int matriz1[2][2], int matriz2[2][2]){
    int novaMatriz [2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            novaMatriz[i][j] = matriz1[i][j] * matriz2[i][j];
        }
        
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Nova Matriz[%d][%d]: %d\n", i,j,novaMatriz[i][j]);
        }
        
    } 

}