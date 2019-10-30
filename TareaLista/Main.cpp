#pragma once
#include "Empleado.h"
#include <iostream>
#include <list>
using namespace std;

int main() {
	Empleado empleado;
	list<Empleado*>lista;

	empleado.agregarEmpleado(lista,new Empleado(01,"Leonel",5000));
	empleado.agregarEmpleado(lista, new Empleado(02, "Juan", 7000));
	empleado.agregarEmpleado(lista, new Empleado(04, "Pablo", 10000));

	empleado.imprimirLista(lista);

	cout << "Cantidad Empleados: "<< empleado.ObtenerCantidadEmpleados(lista)<< "\n";
	cout << "Salario Mayor: " << empleado.obtenerSalarioMayor(lista) << "\n";
	cout << "Total Salarios: "<< empleado.ObtenerTotalSalarios(lista) << "\n";
	
	empleado.encontrarEmpleado(lista, 04);
}


