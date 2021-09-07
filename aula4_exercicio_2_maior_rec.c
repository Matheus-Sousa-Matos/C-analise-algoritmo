#include <stdio.h>
#include <stdlib.h>

int main(){

    int v[10] = {2,5,7,5,1,9,33,121,57,66};

    int m = maior(v,10,0);
    printf("maior = %d",m);

    return 0;
}

int maior(int v[10], int tam, int indice){

    if(tam == 0){
        return v[indice]; //Maior elemento é o primeiro. 
    }
    else{
        if(v[tam - 1] > v[indice]){
            return maior(v,tam-1,tam-1);
        }
        else{
            return maior(v,tam-1,indice); //Caso chegue a zero
        }
    }


}