
//Retorna um vetor contendo a distância entre cada vértice, definida pela matriz de Adjacência
//Matriz de adjacência (numeroVertice x numeroVertice) mostra o peso de um vértice ao outro
//Para o algoritmo de Dijkstra essa matriz não precisa ser simétrica,
//mas todos os elementos são não negativos
float* distanciasAoVertice(int vertice, float** matrizAdjacencia, int numeroVertices);

//Usado na função de calcular distâncias ao vértice para determinar a quantidade de vértices abertos/fechados
//Quando todos os vértices estão fechados dijkstra acaba
int quantidadeDeVerticesFechados(float* verticesAbertos, int numeroVertices);

//Usado na função de calcular distâncias ao vértice para obter o menor custo
//O vértice que possui o menor custo se tornará então o vértice avaliado (parâmetro passado por referência)
float menorCustoAtual(int &verticeAvaliado, int numeroVertices, float* custos, float* verticesAbertos);