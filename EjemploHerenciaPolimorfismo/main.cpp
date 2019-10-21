#include <iostream>
#include <conio.h>

#include "ListaEnlazada.h"
#include "Rectangulo.h"
#include "TrianguloRectangulo.h"
#include "circulo.h"
#include "cuadrado.h"
#include "rombo.h"
#include "trapecio.h"


using namespace std;


int main()
{
	ListaEnlazada lista;

	lista.CrearFigura(rectangulo);
	lista.CrearFigura(circulo);
	lista.CrearFigura(rombo);
	lista.CrearFigura(cuadrado);
	lista.CrearFigura(trapecio);
	lista.CrearFigura(trianguloRectangulo);
	lista.CrearFigura(triangulo);

	lista.ImprimirLista();




	//system("pause");
	_getch();
}