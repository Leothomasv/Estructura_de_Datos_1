#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "nodo.h"
#include "Figura2D.h"

class ListaEnlazada {

private:
	Nodo* primero;

public:
	ListaEnlazada(void);
	void CrearFigura(TipoFigura);
	void unir(Nodo* );
	void ImprimirLista();


};





#endif // LISTAENLAZADA_H



