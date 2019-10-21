#pragma once
#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura2D.h" 

class Cuadrado :public Figura2D {

private:
	float Side;
public:
	Cuadrado();

	Cuadrado(float);

	void setSide(float);
	float getSide();

	float getArea();
	float getPerimetro();

	float getBase();
	float getAltura();

	void imprimirFigura();

	int getTipo();

};

#endif // !CUADRADO_H

