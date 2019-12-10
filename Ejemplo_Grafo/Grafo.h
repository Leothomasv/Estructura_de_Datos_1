#pragma once
#ifndef GRAFO_H
#define GRAFO_H

class Grafo {

private:
	char* vertices;
	int nVertices;
	int** aristas;
	int** costos;

public:
	Grafo();
	void agregarVertice(char);
	void agregarArista(char, char, int);
	void imprimir();
	int obtenerIndiceVertice(char);
	void TransformarGrafo();
};



#endif // !GRAFO_H

