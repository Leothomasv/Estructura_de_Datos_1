
#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura2D.h"

class Rectangulo: public Figura2D
{
private:
	float base, altura;
public:
	Rectangulo();
	Rectangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();

	float getArea();
	float getPerimetro();

	void imprimirFigura();

	int getTipo();
};

#endif