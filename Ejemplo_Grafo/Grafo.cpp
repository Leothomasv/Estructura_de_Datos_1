#include "Grafo.h"
#include <iomanip>
#include <iostream>

using std::setw;

#define INFINITO 9999
int matriz[4][4];



Grafo::Grafo() {
	vertices = 0;
	nVertices = 0;
	aristas = 0;
}

void Grafo::agregarVertice(char id)
{
	char* verticesQpy = new char[nVertices + 1];

	for (int i = 0; i < nVertices; i++) {
		verticesQpy[i] = vertices[i];
	}
	verticesQpy[nVertices] = id;

	if (vertices != 0)
		delete vertices;

	vertices = verticesQpy;

	//-------------------------------------
	//seccion de aristas/costos filas
	int** aristasFilaQpy = new int* [nVertices + 1];
	int** costosFilaQpy = new int* [nVertices + 1];
	
	for (int i = 0; i < nVertices; i++) {
		aristasFilaQpy[i] = aristas[i];
		costosFilaQpy[i] = costos[i];
	}

	if (aristas != 0)
		delete aristas;
	if (costos != 0)
		delete costos;

	aristas = aristasFilaQpy;
	costos = costosFilaQpy;

	//aristas columnas 
	for (int i = 0; i < nVertices; i++) {

		int* aristasColuQpy = new int[nVertices + 1];
		int* costosColQpy = new int[nVertices + 1];

		for (int j = 0; j < nVertices; j++) {
			aristasColuQpy[j] = aristas[i][j];
			costosColQpy[j] = costos[i][j];
		}

		if (aristas[i] != 0)
			delete aristas[i];

		if (costos[i] != 0)
			delete costos[i];

		aristasColuQpy[nVertices] = 0;
		costosColQpy[nVertices] = INFINITO;
		

		aristas[i] = aristasColuQpy;
		costos[i] = costosColQpy;
	}

	int* aristaUltimaFila = new int[nVertices + 1];
	int* costosUltimaFila = new int[nVertices + 1];
	for (int i = 0; i <= nVertices; i++) {
		aristaUltimaFila[i] = 0;
		costosUltimaFila[i] = INFINITO;
	}
	aristas[nVertices] = aristaUltimaFila;
	costos[nVertices] = costosUltimaFila;
	nVertices++;
}

void Grafo::agregarArista(char origen, char destino, int costo)
{
	int fila = obtenerIndiceVertice(origen);
	int columna = obtenerIndiceVertice(destino);

	if (fila != -1 && columna != -1) {
		aristas[fila][columna] = 1;
		aristas[columna][fila] = 1;

		costos[fila][columna] = costo;
		costos[columna][fila] = costo;

		matriz[fila][columna] = costo;
		matriz[columna][fila] = costo;
		
	}


}

int Grafo::obtenerIndiceVertice(char id) {
	for (int i = 0; i < nVertices; i++) {
		if (vertices[i] == id) {
			return i;
		}
	}
}

void Grafo::Floyd(int b[][4])
{
	int i, j, k;
	for (k = 0; k < nVertices; k++)
	{
		for (i = 0; i < nVertices; i++)
		{
			for (j = 0; j < nVertices; j++)
			{
				if ((b[i][k] * b[k][j] != 0) && (i != j))
				{
					if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
					{
						b[i][j] = b[i][k] + b[k][j];
					}
				}
			}
		}
	}
	for (i = 0; i < nVertices; i++)
	{
		cout << "\nCosto Minimo respecto al Nodo:" << i << endl;
		for (j = 0; j < nVertices; j++)
		{
			cout << b[i][j] << "\t";
		}

	}


}

/////// DIJKSTRA///////////////////////
int Grafo::minDistance(int dist[], bool sptSet[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < nVertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void Grafo::printDijkstra(int dist[])
{
	printf("\tVertice \t Distancia desde el origen\n");
	for (int i = 0; i < nVertices; i++)
		printf("\t%d \t\t\t %d\n", i, dist[i]);
}

void Grafo::Dijkstra(int graph[][4], int src)
{
	int dist[4]; 

	bool sptSet[4];  

	for (int i = 0; i < nVertices; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < nVertices - 1; count++) {
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < nVertices; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printDijkstra(dist);

}

void Grafo::imprimir() {
	/*cout << setw(2) << " ";
	for (int i = 0; i < nVertices; i++) {
		cout << setw(2) << vertices[i];
	}

	cout << "\n";
	for (int i = 0; i < nVertices; i++) {

		cout << setw(2) << vertices[i];
		for (int j = 0; j < nVertices; j++) {
			cout << setw(2) << aristas[i][j];
		}
		cout << "\n";
	}*/

	cout << setw(6) << " ";
	for (int i = 0; i < nVertices; i++) {
		cout << setw(6) << vertices[i];
	}
	cout << "\n";
	for (int i = 0; i < nVertices; i++) {
		costos[i][i] = 0;
		cout << setw(6) << vertices[i];
		for (int j = 0; j < nVertices; j++) {
			cout << setw(6) << costos[i][j];
		}
		cout << "\n";
	}
	cout << "\n\n\n";
	cout << "<<<FLOYD>>>\n";
	Floyd(matriz);
	
	cout << "\n\n\n";
	cout << "<<<Dijkstra>>\n";
	Dijkstra(matriz, 0);
}


