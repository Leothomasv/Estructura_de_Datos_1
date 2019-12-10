#pragma once
#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
using namespace std;

class Grafo {

private:
	char* vertices;
	int** aristas;
	int** costos;

public:
	int nVertices;
	Grafo();
	void agregarVertice(char);
	void agregarArista(char, char, int);
	void imprimir();
	int obtenerIndiceVertice(char);
	
	void Floyd(int b[][4]);

	void  Dijkstra(int graph[][4], int src);
	int minDistance(int dist[], bool sptSet[]);
	void printDijkstra(int dist[]);
};



#endif // !GRAFO_H

