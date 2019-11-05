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

void ListaEnlazada::imprimirLista() {
	cout << endl;
	cout << endl;
	if (primero->siguiente==nullptr&&primero->abajo==nullptr)
	{
		cout << "["<<primero->pagina << "]";
		return;
	}
	bool entrar = true;
	NodoPagina* actual = primero;
	NodoPaginaRedirect* tmp = primero->siguiente;
	while (tmp != nullptr)
	{
		if (actual != nullptr)
		{
			if (actual->pagina == primero->pagina || entrar)
			{
				cout << "[" << actual->pagina << "]" << "->";

				actual = actual->abajo;
				entrar = false;
			}
		}
		cout << "[" << tmp->pagina << "]";
		tmp = tmp->siguiente;
		if (tmp == nullptr)
		{
			if (actual != nullptr)
			{
				if (actual->siguiente == nullptr)
				{
					if (actual->abajo == nullptr && actual->siguiente == nullptr)
					{
						cout << endl;
						cout << "[" << actual->pagina << "]" << "->";
						return;
					}
					cout << endl;
					cout << "[" << actual->pagina << "]" << "->";
					actual = actual->abajo;
					tmp = actual->siguiente;
					entrar = true;
					
					cout << endl;
				}
				else {
					cout << endl;
					tmp = actual->siguiente;
					entrar = true;
				}
			}
			else {
				return;
			}
		}
	}
}

