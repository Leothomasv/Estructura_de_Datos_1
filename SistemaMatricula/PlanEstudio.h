#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//struct materia {
//
//	char codigo[10];
//	char nombre[20];
//	int uv;
//	char requisito[10];
//
//	int cantiHijos;
//
//	materia** hijos;//arreglo de apuntadores
//
//	materia(){
//		strcpy_s(codigo, "-1");
//		strcpy_s(nombre, "-1");
//		strcpy_s(requisito, "-1");
//		uv = 0;
//		cantiHijos = 0;
//		hijos = 0;
//	}
//
//	materia( char _codigo[10], char _nombre[20], int _uv, char _requisito[10]) {
//
//		strcpy_s(codigo,_codigo);
//		strcpy_s(nombre, _nombre);
//		strcpy_s(requisito, _requisito);
//		uv = _uv;
//		cantiHijos = 0;
//		hijos = 0;
//	}
//};

struct materia {//memoria
	string nombre;
	string codigo;
	int uv;
	materia* hijos;
	int cantiHijos;
	materia* guardar;
	materia(string codigo, string nombre, int _uv) {
		this->codigo = codigo;
		this->nombre = nombre;
		uv = _uv;
		cantiHijos = 0;
		hijos = 0;
	}
};

struct HijosFile {
	char Hijo[6];
};

struct materiaFile {
	char codigo[10];
	char nombre[30];
	int uv;
	HijosFile hijos [4];

	materiaFile() {
		strcpy(codigo, "-1");
		strcpy(nombre, "-1");
		uv = 0;
	}
};

class PlanEstudio {
private:
	bool estaVacio();
	materia* buscarRec(materia*, string);
	void imprimirRec(materia*);
public:
	materia** raiz;
	PlanEstudio();
	materia* buscar(string);
	void imprimir();
	void agregarMateria(string, string, int, string);

	//nuevas 
	void crearPensum(string);
	void leerPensum(string);
};


#endif 

