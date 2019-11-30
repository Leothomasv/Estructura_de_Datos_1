#pragma once
#ifndef GRAFO_H
#define GRAFO_H

class Grafo {

private:
	char* vertices;
	int nVertices;
	int** aristas;

public:
	Grafo();
	void agregarVertice(char);
	void agregarArista(char, char);
	void imprimir();
	int obtenerIndiceVertice(char);
};



#endif // !GRAFO_H

