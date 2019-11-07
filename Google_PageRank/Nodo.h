#pragma once
#ifndef NODO_H
#define NODO_H

#include <string>
#include <iostream>
using namespace std;

struct NodoPaginaRedirect {

	string pagina;
	NodoPaginaRedirect* siguiente;

	NodoPaginaRedirect(string page, NodoPaginaRedirect* siguiente) {
		this->pagina = page;
		this->siguiente = siguiente;

	}

	NodoPaginaRedirect() {
		pagina = "";
	}
};

struct NodoPagina {
	int enlaces;
	string pagina;
	double PageRank;
	NodoPagina* abajo;
	NodoPaginaRedirect* siguiente;

	NodoPagina(string pagina, NodoPagina* abajo, NodoPaginaRedirect* siguiente, double PageRank) {

		this->pagina = pagina;
		this->PageRank = PageRank;
		this->abajo = abajo;
		this->siguiente = siguiente;
	}

	NodoPagina() {
		pagina = "";
		PageRank = 0;
		enlaces = 0;
	}



};


#endif // !NODO_H