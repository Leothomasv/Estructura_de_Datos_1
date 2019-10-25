#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <list>
using namespace std;


class Empleado {

private:
	int codigo;
	string nombre;
	float salario;

public:
	void esVacia ();
	void agregarEmpleado(list<string>);
	int obtenerCantidadEmpleado();
	float obtenerTotalSalarios();
	float obtenerSalarioMayor();
	Empleado encontrarEmpleado();
	


};


#endif // !EMPLEADO_H
