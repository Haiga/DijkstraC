
//Retorna um vetor contendo a dist�ncia entre cada v�rtice, definida pela matriz de Adjac�ncia
//Matriz de adjac�ncia (numeroVertice x numeroVertice) mostra o peso de um v�rtice ao outro
//Para o algoritmo de Dijkstra essa matriz n�o precisa ser sim�trica,
//mas todos os elementos s�o n�o negativos
float* distanciasAoVertice(int vertice, float** matrizAdjacencia, int numeroVertices);

//Usado na fun��o de calcular dist�ncias ao v�rtice para determinar a quantidade de v�rtices abertos/fechados
//Quando todos os v�rtices est�o fechados dijkstra acaba
int quantidadeDeVerticesFechados(float* verticesAbertos, int numeroVertices);

//Usado na fun��o de calcular dist�ncias ao v�rtice para obter o menor custo
//O v�rtice que possui o menor custo se tornar� ent�o o v�rtice avaliado (par�metro passado por refer�ncia)
float menorCustoAtual(int &verticeAvaliado, int numeroVertices, float* custos, float* verticesAbertos);