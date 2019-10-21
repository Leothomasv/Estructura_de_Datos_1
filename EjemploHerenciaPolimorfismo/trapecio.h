#pragma once
#ifndef TRAPECIO_H
#define TRAPECIO_H

#include "Figura2D.h" 

class Trapecio: public Figura2D {

private:
	float Base1, Base2,altura, Diagonal1, Diagonal2;

public:
	Trapecio();
	Trapecio(float, float, float, float, float);

	void setBase1(float);
	float getBase1();

	void setAltura(float);
	float getAltura();

	void setBase2(float);
	float getBase2();

	void setDiagonal1(float);
	float getDiagonal1();

	void setDiagonal2(float);
	float getDiagonal2();

	float getArea();
	float getPerimetro();

	void imprimirFigura();

	int getTipo();
};
#endif // !TRAPECIO_H
