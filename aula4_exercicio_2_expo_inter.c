#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int k[5] = {1,2,3,4,5};

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < 5; i++)
    {
        k[i] = pow(k[i], n);
        printf("k[i]: %d\n", k[i]);
    }

    return 0;
}