#pragma once
#include <string>
#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

#ifndef ARCHIVOS_H
#define ARCHIVOS_H
class functions { //nuevo herencia
public:
	ListaEnlazada lista;
	void lecturaHTML(string);
	void buscarHref(string);
	int cantidadHref(string);

	void findKeywords();

	void calcularPR();

};
#endif // !ARCHIVOS_H



