#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <string>
#include "Nodo.h"
#include <vector>
#include "ListaEnlazada.h"

using namespace std;

class ListaEnlazada {
public:
	NodoPagina* primero;
	NodoPaginaRedirect* abajo;
	vector<NodoPagina*>Pr;
	bool estaVacia();
	ListaEnlazada(void);
	NodoPagina* ExtraerNodosPagina();
	void agregar(string);
	void agregarSiguiente(string);
	void agregarAbajo(string);
	void imprimirLista();
	void LimpiarLista();
	int extraerRepetidos(string);
	void asignarEnlaces();
	void ImprimirPR();
	void CalcularPR(NodoPagina*, int);
	void ImprimirVector();
	double ExtraerPR(string);
	void Ordenar();

};

#endif // !LISTAENLAZADA_H
