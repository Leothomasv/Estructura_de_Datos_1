#include "Cuadrado.h"
#include <iostream>

using namespace std;

Cuadrado::Cuadrado() : Side(0) {}

Cuadrado::Cuadrado(float Side)
{
	setSide(Side);
}

void Cuadrado::setSide(float b)
{
	if (b >= 0)
		this->Side = b;
	else
		cout << "Error de ingreso en lado del cuadrado";
}
float Cuadrado::getSide()
{
	return this->Side;
}

float Cuadrado::getArea()
{
	return Side * Side;
}

float Cuadrado::getPerimetro()
{
	return Side * 4;
}
float Cuadrado::getAltura()
{
	return this->Side;
}

float Cuadrado::getBase()
{
	return this->Side;
}

void Cuadrado::imprimirFigura()
{
	cout << "Cuadrado: { Base: " << getBase() << ", Altura: "
		<< getAltura() << ", Area: " << getArea() << ", Perimetro: "
		<< getPerimetro() << " }\n";
}

int Cuadrado::getTipo()
{
	return TipoFigura::cuadrado;  // Tipo Cuadrado
}