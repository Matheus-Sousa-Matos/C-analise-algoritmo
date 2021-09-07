//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int x,y,z;

} Struct1;

int main(){

    int n = 3;
    Struct1 vetor_str[n];
    Struct1 matriz_str[n][n];
    //Preenchimento inicial do vetor.
    for (int i = 0; i < n; i++){
        vetor_str[i].x = 2;
        vetor_str[i].y = 1;
        vetor_str[i].z = 0;
    }
    matriz_str[n][n] = rotina(vetor_str, n);
}

Struct1 rotina(Struct1 *vetor_str, int n){
    
    Struct1 matriz_str[n][n];

    printf("vetor_str: %d\n", vetor_str[0].x);

    for(int i = 0; i < n; i ++){
        for (int j = 0; i < n; j++)
        {
            matriz_str[i][j].x = vetor_str[i].x;
            matriz_str[i][j].y = vetor_str[i].y;
            matriz_str[i][j].z = vetor_str[i].z;
        }
    }
    return matriz_str[n][n];
}