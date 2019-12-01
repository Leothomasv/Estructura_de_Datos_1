#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H
#include <iostream>
using namespace std;


struct materia {

	int codigo;
	char nombre [20];
	int uv;
	int anio;
	int periodo;
	int cantiHijos;


	materia** hijos;


	materia(int _codigo, char _nombre, int _uv) {

		codigo = _codigo;
		nombre[20] = _nombre;

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
	void agregarMateria(int codigo, char nombre, int uv, int CodigoPadre);
public:
	PlanEstudio();
	void agregarMateria(int, const char*, int, int);
	materia* buscar(int);
	void imprimir();


};





#endif 