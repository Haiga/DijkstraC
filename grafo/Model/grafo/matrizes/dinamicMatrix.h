#pragma once

//Retorna um ponteiro para um array din�mico de tamanho passado por par�metro
float* alocarArray(int tamanho);
//Atribui ao arranjo, o valor passado como par�metro
//value: Valor que se deseja atribuir
//tamanho: � at� qual posi��o se deseja atribuir o valor
void setValue(float* arranjo, int tamanho, float value);
//Retorna um ponteiro de ponteiro para uma matriz de float, com nLinha x nColuna elementos 
float** alocarMatriz(int nLinha, int nColuna);