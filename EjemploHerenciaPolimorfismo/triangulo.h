#pragma once
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura2D.h"

class Triangulo : public Figura2D {

private:
	float base, altura;
public:
	Triangulo();

	Triangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();

	float getArea();
	float getPerimetro();

	void imprimirFigura();

	int getTipo();

};


#endif // !TRIANGULO_H
