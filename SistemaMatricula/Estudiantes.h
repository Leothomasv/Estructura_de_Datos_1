#pragma once
#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Estudiantes {

	int NumeroCuenta;
	char NombreEstudiante[50];
	char codigoPlanEstudio [40];
	Estudiantes(){};


	void agregarEstudiante();
	void mostrarPlanesEstudio();
	void leerEstudiante();
	void matricular(string codigo, string nombre, int uv, int nota);
	void obtenerPromedio();
	string obtenerCarrera();
	void registrarNotas();
};


struct MateriMatriculada {

	char codigo[20];
	char nombre[100];
	int uv;
	int nota;
};




#endif // !ESTUDIANTES_H

