#include <iostream>
#include "ListaEnlazada.h"
#include "Figura2D.h"
#include "Rectangulo.h"
#include "TrianguloRectangulo.h"
#include "circulo.h"
#include "cuadrado.h"
#include "rombo.h"
#include "trapecio.h"
#include "triangulo.h"


#include <iostream>

using namespace std;

ListaEnlazada::ListaEnlazada(void):primero(nullptr){}


void ListaEnlazada::CrearFigura(TipoFigura tipo) {

	Figura2D* figura;
	Nodo* nuevo;

	
	switch (tipo) {

	case rectangulo:
		figura = new Rectangulo(10, 20);
		nuevo = new Nodo(figura, nullptr);
		unir(nuevo);
		break;
	case trianguloRectangulo:
		figura = new TrianguloRectangulo(19, 5);
		nuevo = new Nodo(figura, nullptr);
		unir(nuevo);
		break;
	case circulo:
		figura = new Circulo(5);
		nuevo = new Nodo(figura, nullptr);
		unir(nuevo);
		break;
	case cuadrado:
		figura = new Cuadrado(10);
		nuevo = new Nodo(figura, nullptr);
		unir(nuevo);
		break;
	
	case triangulo:
		figura = new Triangulo(5, 10);
		nuevo = new Nodo(figura, nullptr);
		unir(nuevo);
		break;

	case rombo:

		break;
	case trapecio:

		break;



	}

}

void ListaEnlazada::unir(Nodo* figura){

	Nodo* actual = primero;
	while (actual != nullptr) {

		actual->getFigura()->imprimirFigura();
		actual = actual->getSiguiente();

	}

}
