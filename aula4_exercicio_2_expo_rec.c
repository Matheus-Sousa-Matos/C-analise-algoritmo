#include <stdio.h>
#include <stdlib.h>

	int main() {
		
		int k = 2;
		int n = 4;
		
		int resultado = exponencial(k, n);
		
		printf("resultado: %d", resultado);

	}
	
	int exponencial(int k, int n) {
		
		if (n != 0) {
			return k * exponencial(k, n - 1);
		} else {
			return 1;
		}
		
	}

