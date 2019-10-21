#include "Rombo.h"
#include <iostream>

using namespace std;

Rombo::Rombo() : Diagonal1(0), Diagonal2(0) {}

Rombo::Rombo(float Diagonal1, float Diagonal2)
{
	setDiagonal1(Diagonal1);
	setDiagonal2(Diagonal2);
}

void Rombo::setDiagonal1(float a)
{
	if (a >= 0)
		this->Diagonal1 = a;
	else
		cout << "Error de ingreso en diagonal";
}

float Rombo::getDiagonal1()
{
	return this->Diagonal1;
}

void Rombo::setDiagonal2(float b)
{
	if (b >= 0)
		this->Diagonal2 = b;
	else
		cout << "Error de ingreso en diagonal";
}
float Rombo::getDiagonal2()
{
	return this->Diagonal2;
}

float Rombo::getArea()
{
	return (Diagonal1 * Diagonal2) / 2;
}
float Rombo::getPerimetro() {
	return 4 * (sqrt(Diagonal1 * Diagonal1 + Diagonal2 * Diagonal2) / 2);
}

void Rombo::imprimirFigura()
{
	cout << "Rombo: { Diagonal 1: " << getDiagonal1() << ", Diagonal 2: " << getDiagonal2() << ", Area:" << getArea() << ", Perimetro: "
		<< getPerimetro() << " }\n";
}

int Rombo::getTipo()
{
	return TipoFigura::rombo;  // Tipo Rombo
}