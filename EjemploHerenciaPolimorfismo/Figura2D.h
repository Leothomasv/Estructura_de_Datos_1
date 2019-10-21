

#ifndef FIGURA2D_H

#define FIGURA2D_H

enum TipoFigura{rectangulo, trianguloRectangulo, triangulo, cuadrado, circulo, rombo, trapecio};

class Figura2D
{
public:

	virtual float getArea() = 0;
	virtual float getPerimetro() = 0;
	virtual int getTipo() = 0;
	virtual void imprimirFigura() = 0;

};

#endif