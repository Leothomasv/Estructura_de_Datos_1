#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <string>
#include "Nodo.h"
#include "ListaEnlazada.h"

using namespace std;

class ListaEnlazada{

	NodoPagina* primero;
	NodoPaginaRedirect* abajo;

public:
	bool estaVacia();
	ListaEnlazada(void);
	void agregar(string);
	void agregarSiguiente(string);
	void agregarAbajo(string);
	void imprimirLista();

};

#endif // !LISTAENLAZADA_H

