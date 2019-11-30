#pragma once
#include <string>
using namespace std;

#ifndef ARCHIVO_H
#define ARCHIVO_H


struct NombreMateria {
	string nombre;
};

struct MateriaArchivo {

	string codigo;
	string nombre;
	int UV_req;
	int UV;
	int Anio;
	int perido;

	NombreMateria hijos[4];
	NombreMateria padre;
};

struct ArchivoBinario {
	int Codigo_Plan_De_Estudio;
	string NombrePlanEstudio;
	int TotalClases;
	int TotalUnidadesValorativas;
	int NumeroBloquesConocimiento; // Este valor indica la cantidad de columnas que tendrá por cada grupo de clases en el plan de estudio.

	void crearPensum();

};


struct Estudiantes {

	int NumeroCuenta;
	string NombreEstudiante;
	int Codigo_PlanEstudio;
	double IndiceAcademico;
	int ClasesAprobadas;

	Estudiantes() {
		NumeroCuenta = 0;
		NombreEstudiante = "";
		Codigo_PlanEstudio = 0;
		IndiceAcademico = 0;
		ClasesAprobadas = 0;
	}

	void agregarEstudiante();
	void leerEstudiantes();
};


#endif // !ARCHIVO_H


