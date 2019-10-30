#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <list>
#include <string>
using namespace std;

class Empleado {
private:
	int codigo;
	string Nombre;
	float Salario;
public:
	Empleado(void);
	Empleado(int,string,float);

	void agregarEmpleado(list<Empleado*>&, Empleado*);
	int ObtenerCantidadEmpleados(list<Empleado*>&);
	float ObtenerTotalSalarios(list<Empleado*>&);
	float obtenerSalarioMayor(list<Empleado*>&);
	void encontrarEmpleado(list<Empleado*>&, int);
	void imprimirLista(list<Empleado*>& );
};
#endif // !EMPLEADO_H
