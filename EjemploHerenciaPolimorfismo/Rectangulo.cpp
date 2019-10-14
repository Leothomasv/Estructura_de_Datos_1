
#include "Rectangulo.h"
#include <iostream>

using namespace std;

Rectangulo::Rectangulo(): base(0), altura(0)
{
}

Rectangulo::Rectangulo(float b, float a)
{
	setBase(b);
	setAltura(a);
}

void Rectangulo::setBase(float b)
{
	if(b >= 0)
		this->base = b;
	else
		cout << "Error de ingreso en base";
}

void Rectangulo::setAltura(float a)
{
	if(a >= 0)
		this->altura = a;
	else 
		cout << "Error de ingreso en altura";
}

float Rectangulo::getBase()
{
	return this->base;
}

float Rectangulo::getAltura()
{
	return this->altura;
}

float Rectangulo::getArea()
{
	return base * altura;
}

float Rectangulo::getPerimetro()
{
	return 2*(base + altura);
}

void Rectangulo::imprimirFigura()
{
	cout << "Rectangulo: {base: " << getBase() << ", altura: "
		<< getAltura() << ", area: " << getArea() << ", perimetro: " 
		<< getPerimetro() << "}\n";
}

int Rectangulo::getTipo()
{
	return TipoFigura::trianguloRectangulo; // Tipo Rectangulo
}