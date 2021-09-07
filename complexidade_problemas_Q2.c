//Autor: Matheus de Sousa Matos
//Curso: Engenharia de Software
//Período: 6º Semestre
//Matrícula: UC19104412"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n1,n2, res;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    fflush(stdin);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);  

    res = n1;
    for (int i = 1; i < n2; i++){
        res = res * n1;
    }
    printf("Resultado: %d", res);

}