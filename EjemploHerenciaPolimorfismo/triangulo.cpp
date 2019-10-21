#include "triangulo.h"
#include <iostream>
#include <cmath>

using std::cout;


Triangulo::Triangulo() : base(0), altura(0)
{}

Triangulo::Triangulo(float b, float a)
{
	setBase(b);
	setAltura(a);
}

void Triangulo::setBase(float b)
{
	if (b > 0)
		this->base = b;
	else
		cout << "Error en Ingreso de Base";
}

void Triangulo::setAltura(float a)
{
	if (a > 0)
		this->altura = a;
	else
		cout << "Error en Ingreso de Altura";
}

float Triangulo::getBase()
{
	return this->base;
}

float Triangulo::getAltura()
{
	return this->altura;
}

float Triangulo::getArea()
{
	return (base * altura) / 2;
}

float Triangulo::getPerimetro()
{
	return (base + altura + sqrt(base * base + altura * altura));
}

int Triangulo::getTipo()
{
	return TipoFigura::triangulo; // Triangulo
}

void Triangulo::imprimirFigura()
{
	cout << "Triangulo: { Base: " << getBase() << ", Altura: " << getAltura()
		<< ", Area: " << getArea() << ", Perimetro: " << getPerimetro() << " }\n";
}