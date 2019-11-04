#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada(void) : primero(nullptr), abajo(nullptr) {
}

bool ListaEnlazada::estaVacia()
{
	return primero == nullptr || abajo == nullptr;
}

void ListaEnlazada::agregar(string pagina) {
	NodoPagina* nuevo = new NodoPagina(pagina, nullptr, nullptr, 0);
	int contador;
	if (estaVacia()) {
		primero = nuevo;

	}
}
void ListaEnlazada::agregarSiguiente(string pagina) {
	NodoPaginaRedirect* nuevo = new NodoPaginaRedirect(pagina, nullptr);
	if (estaVacia())
	{

		abajo = nuevo;
	}
	else {
		NodoPaginaRedirect* actual = abajo;
		while (actual->siguiente != nullptr)
		{
			actual = actual->siguiente;
		}
		actual->siguiente = nuevo;
		NodoPagina* tmp = primero;
		while (tmp->abajo != nullptr)
		{
			tmp = tmp->abajo;
		}
		tmp->siguiente = abajo;
		int x = 0;
	}
}
void ListaEnlazada::agregarAbajo(string pagina) {
	NodoPagina* nuevo = new NodoPagina(pagina, nullptr, nullptr, 0);
	NodoPagina* actual = primero;
	while (actual->abajo != nullptr)
	{
		actual = actual->abajo;
	}
	actual->abajo = nuevo;
	abajo = nullptr;
}


