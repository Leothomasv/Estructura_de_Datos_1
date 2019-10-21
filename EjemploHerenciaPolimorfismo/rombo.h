#pragma once
#ifndef ROMBO_H
#define ROMBO_H

#include "Figura2D.h"

class Rombo : public Figura2D {

private :
	float Diagonal1, Diagonal2;
public:
	Rombo();

	Rombo(float, float);

	void setDiagonal1(float);
	float getDiagonal1();

	void setDiagonal2(float);
	float getDiagonal2();

	float getArea();
	float getPerimetro();

	void imprimirFigura();

	int getTipo();





};
#endif // !1
