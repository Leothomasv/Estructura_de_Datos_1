

#ifndef TRIANGULOREC_H

#define TRIANGULOREC_H

#include "Figura2D.h"

class TrianguloRectangulo: public Figura2D
{
private:
	float base, altura;
public:
	TrianguloRectangulo();
	TrianguloRectangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();

	float getArea();
	float getPerimetro();

	int getTipo();

	void imprimirFigura();

	float getHipotenusa();

};


#endif