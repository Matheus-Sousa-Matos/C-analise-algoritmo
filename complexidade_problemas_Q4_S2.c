//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412

#include <stdio.h>
#include <stdlib.h>

int main(){
    


}

int kesimo (int *v, int tam, int k){
    //Ordenando por Sort;
    v = sort(v,tam);
    return v[k];
}

int sort(int *v, int tam){
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
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

