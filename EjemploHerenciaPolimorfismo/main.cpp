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

	lista.ImprimirLista();




	//system("pause");
	_getch();
}