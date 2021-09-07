//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int v[] = {9,10,3,6,5,4,7,8,1,2};
    int tam = sizeof(v)/sizeof(v[0]);
    int k = tam-2;

    printf("%d\n", tam);
    k = kesimo(v,tam,k);
    printf("%d\n", k);

}

int kesimo (int *v, int tam, int k){
    //Ordenando por Sort;
    v = sort(v,tam);

    for (int i = 0; i < tam; i++)
    {
        printf("v[%d]: %d\n", i, v[i]);
    }
    

    return v[k];
}

int sort(int *v, int tam){
    for (int i = 0; i < tam; i++)
    {
        for (int j = 1; j < tam; j++)
        {
            if (v[j-1] > v[j])
            {
                int x = v[j-1];
                v[j-1] = v[j];
                v[j] = x;
            }
        }
    }
    return v;
    
}

