#pragma once
#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura2D.h" 

class Circulo :public Figura2D {

private:
	double radio;
public:
	Circulo();
	Circulo(double radio);
	
	double getRadio();
	void setRadio(double radio);

	float getArea();
	float getPerimetro();

	void imprimirFigura();

	int getTipo();


};

#endif // 
