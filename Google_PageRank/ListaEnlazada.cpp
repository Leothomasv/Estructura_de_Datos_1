#include "ListaEnlazada.h"
#include <vector>
#include <algorithm>

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
	if (primero->siguiente == nullptr && primero->abajo == nullptr)
	{
		cout << "[" << primero->pagina << "]";
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
NodoPagina* ListaEnlazada::ExtraerNodosPagina() {
	NodoPagina* actual = primero;
	return actual;
}
vector<string>paginas;

void ListaEnlazada::LimpiarLista() {
	int contador = 0;
	int posicion = 0;
	int contador2 = 0;
	int cantidadElementos = 0;
	NodoPagina* actual = primero;
	while (actual != 0)
	{
		NodoPagina* tmp = actual;
		NodoPagina* tmp2 = actual;
		for (int i = 0; i < paginas.size(); i++)
		{
			if (paginas[posicion] == actual->pagina && contador == 0)
			{
				cantidadElementos = extraerRepetidos(paginas[posicion]) - 1;
				if (cantidadElementos ==0)
				{
					posicion++;
					break;
				}
				else {
					tmp = tmp->abajo;
				}
				contador++;
			}
			if (contador != 0)
			{
				if (tmp->pagina == paginas[posicion] && contador2 < extraerRepetidos(paginas[posicion]))
				{
					tmp2->abajo = tmp->abajo;
					delete tmp;
					
					tmp = primero;
					contador2++;
					if (contador2 == cantidadElementos)//
					{
						posicion++;
						if (posicion==paginas.size())
						{
							return;
						}
						break;
					}
				}
			}
			int x = 0;
			i = 0;
			tmp2 = tmp;
			tmp = tmp->abajo;
		}		
		actual = actual->abajo;
		contador2 = 0;
		contador = 0;
	}


}

int ListaEnlazada::extraerRepetidos(string pagina) {
	NodoPagina* actual = primero;
	int contador = 0;
	while (actual != nullptr)
	{
		paginas.push_back(actual->pagina);
		if (pagina == actual->pagina)
		{
			contador++;
		}
		actual = actual->abajo;
	}
	auto end = paginas.end();
	for (auto it = paginas.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	paginas.erase(end, paginas.end());
	return contador;
}


