#include "circulo.h"

#include <iostream>

using namespace std;

Circulo::Circulo() : radio(0) {}

Circulo::Circulo(double lado)
{
	setRadio(lado);
}

void Circulo::setRadio(double b)
{
	if (b >= 0)
		this->radio = b;
	else
		cout << "Error de ingreso en radio";
}

double Circulo::getRadio()
{
	return this->radio;
}

float Circulo::getArea()
{
	return 3.1416 * (radio * radio);
}

float Circulo::getPerimetro()
{
	return 2 * 3.1416 * (radio);
}

void Circulo::imprimirFigura()
{
	cout << "Circulo: { Radio: " << getRadio() << ", Area " << getArea() << ", Perimetro: "
		<< getPerimetro() << " }\n";
}

int Circulo::getTipo()
{
	return TipoFigura::circulo;  // Tipo Circulo
}
