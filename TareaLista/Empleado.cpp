#include "Empleado.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;


Empleado::Empleado(){}

Empleado::Empleado(int codigo,string nombre,float salario) {
	this->codigo = codigo;
	this->Nombre = nombre;
	this->Salario = salario;
}

void Empleado::agregarEmpleado(list<Empleado*>& lista,Empleado* E) {
	Empleado* empleado = new Empleado(E->codigo, E->Nombre, E->Salario);
	if (lista.empty())
	{
		lista.push_front(empleado);
	}
	else {
		lista.push_back(empleado);
	}
}

float Empleado::ObtenerTotalSalarios(list<Empleado*>& lista) {
	float salarioTotal = 0;
	for (auto const & x : lista) {
		salarioTotal += x->Salario;
	}
	return salarioTotal;
}

float Empleado::obtenerSalarioMayor(list<Empleado*>& lista) {
	float salarioMayor = 0;
	for (auto const& x : lista) { //auto para que el compilador use el tipo de dato adecuado.
		if (x->Salario > salarioMayor)
		{
			salarioMayor = x->Salario;
		}
	}
	return salarioMayor;
}

void Empleado::encontrarEmpleado(list<Empleado*>& lista, int codigo) {
	for (auto& x : lista) {
		if (codigo == x->codigo)
		{
			cout << "Empleado: { Nombre: " << x->Nombre << " ,Codigo: " << x->codigo << " ,Salario: " << x->Salario << " }\n";
		}
	}
}


int Empleado::ObtenerCantidadEmpleados(list<Empleado*>& lista) {
	return lista.size();
}

void Empleado::imprimirLista(list<Empleado*>& lista) {
	for (auto& x : lista) {
		cout << "Empleado: { Nombre: " << x->Nombre << " ,Codigo: " << x->codigo << " ,Salario: " << x->Salario << " }\n";

	}
}