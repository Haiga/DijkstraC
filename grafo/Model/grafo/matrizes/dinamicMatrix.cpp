#include <stdlib.h>
#include "dinamicMatrix.h"
#define infinito 1000000000000


float* alocarArray(int tamanho)
{
	float* inicio;
	inicio = (float*)malloc(tamanho * sizeof(float));
	return inicio;
}

void setValue(float* arranjo, int tamanho, float value) {
	sizeof(arranjo)/sizeof(float);
	for (int i = 0; i < tamanho; i++) {
		arranjo[i] = value;
	}
}

float** alocarMatriz(int nLinha, int nColuna)
{
	float **matriz = (float**)malloc(nLinha * sizeof(float*));

	for (int i = 0; i < nLinha; i++) {
		matriz[i] = alocarArray(nColuna);
		setValue(matriz[i], nColuna, infinito);
	}
	
	return matriz;
}
