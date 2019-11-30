#include "Archivo.h"
#include <iostream>
#include <fstream>

using namespace std;

void Estudiantes::agregarEstudiante()
{
	ofstream fileEstu("Estudiantes.dat", ios::out | ios::app | ios::binary);

	if (!fileEstu) {
		cout << "Error en apertura archivo estudiantes" << endl;
		return;
	}

	int CantidadEstudiantes = 0;
	cout << "Define cantidad de estudiantes a ingresar: ";
	cin >> CantidadEstudiantes;

	Estudiantes nuevo;

	for (int x = 0; x < CantidadEstudiantes; x++) {

		cout << "Ingrese numero de cuenta: ";
		cin >> nuevo.NumeroCuenta;

		cout << "Ingrese nombre del estudiante: ";
		cin >> nuevo.NombreEstudiante;

		cout << "Ingrese plan de estudio: ";
		cin >> nuevo.Codigo_PlanEstudio;
		//aqui tiene que ir un if para comparar si existe el plan de estudio

		//para agregar indice y total de clases se deben de parametro

		fileEstu.write(reinterpret_cast<const char*>(&nuevo), sizeof(Estudiantes));
	}
	fileEstu.close();
}
