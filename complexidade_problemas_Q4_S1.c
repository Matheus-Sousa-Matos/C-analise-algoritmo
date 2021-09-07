//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[10] = {2,3,4,5,10,1,7,8,9,6};
    int menor;
    int k;
    
    scanf("%d", &k);
    
    for (int j = 1; j < 10; ++j) {
      int x = vetor[j];
      int i;
      for (i = j-1; i >= 0 && vetor[i] > x; --i) 
         vetor[i+1] = vetor[i];
      vetor[i+1] = x;
    }

    printf("Vetor k-esimo menor: %d", vetor[k]);

}