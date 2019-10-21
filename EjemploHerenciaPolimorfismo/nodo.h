#pragma once
#ifndef NODO_H
#define NODO_H
#include "Figura2D.h"


class Nodo {
	 
private:
	Nodo* siguiente;
	Figura2D* figura;
public: 
	Nodo(void);
	Nodo(Figura2D*, Nodo*);


	Figura2D* getFigura();
	void setFigura(Figura2D*);
	void setSiguiente(Nodo*);
	Nodo* getSiguiente(void);
};





#endif NODO_H