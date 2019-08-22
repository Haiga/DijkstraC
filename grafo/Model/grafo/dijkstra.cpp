#include <stdlib.h>
#include "matrizes\dinamicMatrix.h"
#include "dijkstra.h"
#define infinito 1000000000000

float* distanciasAoVertice(int vertice, float** matrizAdjacencia, int numeroVertices) {
	int verticeAvaliado = vertice - 1;
	float* custos = alocarArray(numeroVertices);
	float* verticesAbertos = alocarArray(numeroVertices);

	setValue(verticesAbertos, numeroVertices, 1);
	setValue(custos, numeroVertices, infinito);
	custos[verticeAvaliado] = 0;
	

	while (1) {

		for (int i = 0; i < numeroVertices; i++) {
			if ((matrizAdjacencia[verticeAvaliado][i]) != infinito && i != verticeAvaliado) {
				if (custos[i] > custos[verticeAvaliado] + matrizAdjacencia[verticeAvaliado][i]) {
					custos[i] = custos[verticeAvaliado] + matrizAdjacencia[verticeAvaliado][i];
				}
			}
		}

		verticesAbertos[verticeAvaliado] = 0;
		if (quantidadeDeVerticesFechados(verticesAbertos, numeroVertices) == numeroVertices) {
			break;
		}

		
		if (menorCustoAtual(verticeAvaliado, numeroVertices, custos, verticesAbertos) >= infinito) {
			break;
		}
	}

	return custos;
}

int quantidadeDeVerticesFechados(float* verticesAbertos, int numeroVertices) {
	int qtdeFechados = 0;
	for (int i = 0; i < numeroVertices; i++) {
		if (!verticesAbertos[i]) {
			qtdeFechados++;
		}
	}
	return qtdeFechados;
}

float menorCustoAtual(int &verticeAvaliado, int numeroVertices, float* custos, float* verticesAbertos) {
	float menor = infinito + 1;
	for (int i = 0; i < numeroVertices; i++) {
		if (menor > custos[i] && verticesAbertos[i]) {
			menor = custos[i];
			verticeAvaliado = i;
		}
	}
	return menor;
}