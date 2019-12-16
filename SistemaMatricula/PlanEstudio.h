#pragma once
#ifndef PLAN_ESTUDIO_H
#define PLAN_ESTUDIO_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct materia {//memoria
	string nombre = "";
	string codigo = "";
	int uv = 0;
	string requisito;
	materia** hijos = 0;
	int cantiHijos = 0;
	int TotalUV = 0;
	string desbloqueo = "";
	materia(){}
	materia(string codigo, string nombre, int _uv, string _requisito,string des) {
		this->codigo = codigo;
		this->nombre = nombre;
		uv = _uv;
		this->requisito = _requisito;
		cantiHijos = 0;
		hijos = 0;
		desbloqueo = des;
	}
};


struct materiaFile {
	char codigo[15];
	char nombre[40];
	int uv;
	char requisito[50];
	char desbloqueo[45];
	materiaFile() {
		strcpy(codigo, "-1");
		strcpy(nombre, "-1");
		strcpy(requisito, "-1");
		strcpy(desbloqueo, "-1");
		uv = 0;
	}
};

class PlanEstudio {
private:
	bool estaVacio();
	materia** buscarRec(materia**, string);
	void imprimirRec(materia*);
public:
	int raices = 0;
	materia** raiz;
	PlanEstudio();
	materia** buscar(string);
	void imprimir();
	void agregarMateria(string, string, int, string,string);
	void obtenerClasesDisponibles();
	void obtenerHistorialAcademico();
	bool claseAprobada(string);
	void ModificarNota(string,int);
	void recorrer(materia**);
	void padres(materia**,string);
	void Rec(string codigo);
	//nuevas
	void crearPensum(string);
	void leerPensum();
	void leerVector();

};


#endif