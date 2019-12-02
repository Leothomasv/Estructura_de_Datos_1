#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct materia {

	string codigo;
	string nombre;
	int uv;
	string requisito;

	int cantiHijos;

	materia** hijos;//arreglo de apuntadores

	materia(){}

	materia(string _codigo, string _nombre, int _uv, string _requisito) {

		codigo = _codigo;
		nombre = _nombre;
		requisito = _requisito;

		uv = _uv;
		cantiHijos = 0;
		hijos = 0;
	}
};


class PlanEstudio {
private:
	materia* raiz;
	bool estaVacio();
	materia* buscarRec(materia*, string);
	void imprimirRec(materia*);
public:
	PlanEstudio();
	void agregarMateria(string, string, int, string);
	materia* buscar(string);
	void imprimir();

	//nuevas 
	void crearPensum(string);
	void leerPensum(string);
};

struct Estudiantes {
	int NumeroCuenta;
	char* NombreEstudiante;
	char* CodPlanEstudio;
	double IndiceAcademico;
	int ClasesAprobadas;
};



#endif 

