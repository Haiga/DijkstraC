#pragma once

//Retorna um ponteiro para um array dinâmico de tamanho passado por parâmetro
float* alocarArray(int tamanho);
//Atribui ao arranjo, o valor passado como parâmetro
//value: Valor que se deseja atribuir
//tamanho: é até qual posição se deseja atribuir o valor
void setValue(float* arranjo, int tamanho, float value);
//Retorna um ponteiro de ponteiro para uma matriz de float, com nLinha x nColuna elementos 
float** alocarMatriz(int nLinha, int nColuna);