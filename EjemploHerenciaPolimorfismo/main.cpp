
#include <iostream>
#include <conio.h>

using namespace std;

#include "Rectangulo.h"
#include "TrianguloRectangulo.h"



void imprimir(Figura2D * figura)
{
	
	figura->imprimirFigura();

	if(figura->getTipo() == TipoFigura::trianguloRectangulo)
	{
		TrianguloRectangulo *tr = (TrianguloRectangulo *)figura;
		cout << "Hipotenusa: " << tr->getHipotenusa() << "\n";
	}
}


int main()
{

	Figura2D * figuras[4];

	figuras[0] = new Rectangulo(8, 6);
	figuras[1] = new Rectangulo(5, 6.3);
	figuras[2] = new TrianguloRectangulo(3.5, 6); 
	figuras[3] = new TrianguloRectangulo(7, 12.5); 

	for(int i = 0; i < 4; i++)
	{
		imprimir(figuras[i]);
	}


	//system("pause");
	_getch();
}