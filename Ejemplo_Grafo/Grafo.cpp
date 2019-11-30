#include "Grafo.h"
#include <iomanip>
#include <iostream>

using std::setw;
using std::cout;


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
	
	//seccion de aristas filas
	int** aristasFilaQpy = new int* [nVertices + 1];
	
	for (int i = 0; i < nVertices; i++) {
		aristasFilaQpy[i] = aristas[i];
	}

	if (aristas != 0)
		delete aristas;

	aristas = aristasFilaQpy;

	//aristas columnas 
	for (int i = 0; i < nVertices; i++) {

		int* aristasColuQpy = new int[nVertices + 1];
		for (int j = 0; j < nVertices; j++) {
			aristasColuQpy[j] = aristas[i][j];
		}

		if (aristas[i] != 0)
			delete aristas[i];

		aristasColuQpy[nVertices] = 0;
		

		aristas[i] = aristasColuQpy;
	}

	int* aristaUltimaFila = new int[nVertices + 1];
	for (int i = 0; i <= nVertices; i++) {
		aristaUltimaFila[i] = 0;
	}
	aristas[nVertices] = aristaUltimaFila;
	nVertices++;
}

void Grafo::agregarArista(char origen, char destino)
{
	int fila = obtenerIndiceVertice(origen);
	int columna = obtenerIndiceVertice(destino);

	if (fila != -1 && columna != -1) {
		aristas[fila][columna] = 1;
	}


}

int Grafo::obtenerIndiceVertice(char id) {
	for (int i = 0; i < nVertices; i++) {
		if (vertices[i] == id) {
			return i;
		}
	}
}

void Grafo::imprimir() {
	
	cout << setw(2) << " ";
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
	}




}
