
#include "TrianguloRectangulo.h"

#include <iostream>

#include <cmath>

using std::cout;


TrianguloRectangulo::TrianguloRectangulo(): base(0), altura(0)
{}

TrianguloRectangulo::TrianguloRectangulo(float b, float a)
{
	setBase(b);
	setAltura(a);
}

void TrianguloRectangulo::setBase(float b)
{
	if(b > 0)
		this->base = b;
	else
		cout << "Error en Ingreso de Base\n";
}

void TrianguloRectangulo::setAltura(float a)
{
	if(a > 0)
		this->altura = a;
	else
		cout << "Error en Ingreso de Altura\n";
}

float TrianguloRectangulo::getBase()
{
	return this->base;
}

float TrianguloRectangulo::getAltura()
{
	return this->altura;
}

float TrianguloRectangulo::getArea()
{
	return (base * altura) / 2;
}

float TrianguloRectangulo::getPerimetro()
{
	return (base + altura + sqrt(base * base + altura * altura));
}

float TrianguloRectangulo::getHipotenusa()
{
	return sqrt(base * base + altura *altura);
}

int TrianguloRectangulo::getTipo()
{
	return TipoFigura::trianguloRectangulo; // TrianguloRectangulo
}

void TrianguloRectangulo::imprimirFigura()
{
	cout << "TrianguloRectangulo: { base: " << getBase() << ", altura: " << getAltura()
		<< ", area: " << getArea() << ", perimetro: " << getPerimetro() << " }\n";
}