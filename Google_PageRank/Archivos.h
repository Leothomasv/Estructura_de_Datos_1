#pragma once
#include <string>
#include <iostream>
#include <dirent.h>
#include "ListaEnlazada.h"

using namespace std;

#ifndef ARCHIVOS_H
#define ARCHIVOS_H
class functions { //nuevo herencia
public:
	ListaEnlazada lista;
	void lecturaHTML(string, int);
	//void buscarHref(string);
	int cantidadHref(string);

	void findKeywords(string);

	void calcularPR();


	void list_dir();






};
#endif // !ARCHIVOS_H

