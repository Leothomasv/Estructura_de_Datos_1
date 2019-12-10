#include "Grafo.h"
#include <iomanip>
#include <iostream>

using std::setw;
using std::cout;

#define INFINITO 9999

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
}

void Grafo::TransformarGrafo() {


}