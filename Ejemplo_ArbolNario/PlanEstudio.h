#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H
#include <iostream>
using namespace std;


struct materia {

	int codigo;
	char* nombre;
	int uv;
	int cantiHijos;

	materia** hijos;


	materia(int _codigo, const char* _nombre,int _uv ) {

		codigo = _codigo;
		nombre = new char[strlen(_nombre)];
		strcpy_s(this->nombre, strlen(_nombre) + 1, _nombre);

		uv = _uv;
		cantiHijos = 0;
		hijos = 0;
	}
};


class PlanEstudio {
private:
	materia* raiz;
	bool estaVacio();
	materia* buscarRec(materia*, int);
	void imprimirRec(materia*);
public:
	PlanEstudio();
	void agregarMateria(int , const char* , int, int );
	materia* buscar(int);
	void imprimir();


};





#endif 

