//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num;

    printf("Informe um numero: ");
    scanf("%d", &num);

    printf("\n");

    imprimeFibo(num);
}

void imprimeFibo(int num){
    int  f1 = 0 ,f2 = 1,f3;

    printf("0| 1");

    while (f2 < num)
    {
        f3 = f2 + f1;             
        printf("| %d", f3);
        f1 = f2;
        f2 = f3;
    }
    
    printf("\n");


}