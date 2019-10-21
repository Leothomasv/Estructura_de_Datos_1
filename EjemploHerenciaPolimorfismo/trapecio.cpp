#include "Trapecio.h"
#include <iostream>

using namespace std;

Trapecio::Trapecio() : Base1(0), Base2(0), altura(0), Diagonal1(0), Diagonal2 (0){}

Trapecio::Trapecio(float Base1, float Base2, float Altura, float _Diagonal1, float _Diagonal2)
{
	setBase1(Base1);
	setBase2(Base2);
	setAltura(Altura);
	setDiagonal1(_Diagonal1);
	setDiagonal2(_Diagonal2);
}

void Trapecio::setBase1(float b)
{
	if (b >= 0)
		this->Base1 = b;
	else
		cout << "Error de ingreso en base";
}

float Trapecio::getBase1()
{
	return this->Base1;
}

void Trapecio::setBase2(float b)
{
	if (b >= 0)
		this->Base2 = b;
	else
		cout << "Error de ingreso en base";
}
float Trapecio::getBase2()
{
	return this->Base2;
}
void Trapecio::setDiagonal1(float b)
{
	if (b >= 0)
		this->Diagonal1 = b;
	else
		cout << "Error de ingreso en base";
}

float Trapecio::getDiagonal1()
{
	return this->Diagonal1;
}

void Trapecio::setDiagonal2(float b)
{
	if (b >= 0)
		this->Diagonal2 = b;
	else
		cout << "Error de ingreso en base";
}
float Trapecio::getDiagonal2()
{
	return this->Diagonal2;
}

void Trapecio::setAltura(float a)
{
	if (a >= 0)
		this->altura = a;
	else
		cout << "Error de ingreso en altura";
}

float Trapecio::getAltura()
{
	return this->altura;
}

float Trapecio::getArea()
{
	return (Base1 + Base2) / 2 * altura;
}
float Trapecio::getPerimetro() {
	return Base1 + Base2 + Diagonal1 + Diagonal2;
}

void Trapecio::imprimirFigura()
{
	cout << "Trapecio: { Base Mayor: " << getBase1() << ", Base Menor: " << getBase2() << ", Altura: " << getAltura() << ", Diagonal 1: " << getDiagonal1() << ", Diagonal 2: " << getDiagonal2() << ", Area: " << getArea() << ", Perimetro: "
		<< getPerimetro() << " }\n";
}

int Trapecio::getTipo()
{
	return TipoFigura::trapecio;  // Tipo Trapecio
}