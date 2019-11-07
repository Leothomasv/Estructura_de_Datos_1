#include "ListaEnlazada.h"
#include <vector>
#include <algorithm>
#include <compare>
#include <fstream>

ListaEnlazada::ListaEnlazada(void) : primero(nullptr), abajo(nullptr) {
}

bool ListaEnlazada::estaVacia() {
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
	if (estaVacia()) {
		abajo = nuevo;
	}
	else {
		NodoPaginaRedirect* actual = abajo;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevo;
		NodoPagina* tmp = primero;
		while (tmp->abajo != nullptr) {
			tmp = tmp->abajo;
		}
		tmp->siguiente = abajo;
		int x = 0;
	}
}

void ListaEnlazada::agregarAbajo(string pagina) {
	NodoPagina* nuevo = new NodoPagina(pagina, nullptr, nullptr, 0);
	NodoPagina* actual = primero;
	while (actual->abajo != nullptr) {
		actual = actual->abajo;
	}
	actual->abajo = nuevo;
	abajo = nullptr;
}

void ListaEnlazada::imprimirLista() {
	cout << endl;
	cout << endl;
	if (primero->siguiente == nullptr && primero->abajo == nullptr) {
		cout << "[" << primero->pagina << "]";
		return;
	}
	bool entrar = true;
	NodoPagina* actual = primero;
	NodoPaginaRedirect* tmp = primero->siguiente;
	while (tmp != nullptr) {
		if (actual != nullptr) {
			if (actual->pagina == primero->pagina || entrar) {
				cout << "[" << actual->pagina << "]" << "->";
				actual = actual->abajo;
				entrar = false;
			}
		}
		cout << "[" << tmp->pagina << "]";
		tmp = tmp->siguiente;
		if (tmp == nullptr) {
			if (actual != nullptr) {
				if (actual->siguiente == nullptr) {
					if (actual->abajo == nullptr && actual->siguiente == nullptr) {
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
	NodoPagina* ptr1, * ptr2, * dup;
	ptr1 = primero;
	while (ptr1 != nullptr && ptr1->abajo != nullptr) {
		ptr2 = ptr1;
		while (ptr2->abajo != nullptr) {
			if (ptr1->pagina == ptr2->abajo->pagina) {
				dup = ptr2->abajo;
				ptr2->abajo = ptr2->abajo->abajo;
				delete(dup);
			}
			else /* This is tricky */
				ptr2 = ptr2->abajo;
		}
		ptr1 = ptr1->abajo;
	}
}

int ListaEnlazada::extraerRepetidos(string pagina) {
	NodoPagina* actual = primero;
	int contador = 0;
	while (actual != nullptr) {
		paginas.push_back(actual->pagina);
		actual = actual->abajo;
	}
	auto end = paginas.end();
	for (auto it = paginas.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}
	paginas.erase(end, paginas.end());
	return contador;
}

void ListaEnlazada::asignarEnlaces() {
	NodoPagina* actual = primero;
	NodoPaginaRedirect* tmp;
	int cantidad = 0;
	while (actual != 0) {
		tmp = actual->siguiente;
		if (tmp == nullptr) {
			actual->enlaces = 0;
		}
		while (tmp != nullptr) {
			cantidad++;
			tmp = tmp->siguiente;
			actual->enlaces = cantidad;
		}
		cantidad = 0;
		actual = actual->abajo;
	}
}

void ListaEnlazada::ImprimirPR() {
	asignarEnlaces();
	cout << "\n\n";
	NodoPagina* actual = primero;
	NodoPagina* tmp = primero;
	CalcularPR(tmp, 0);
	//ImprimirVector();
	cout << "\n\n\n";
	while (actual != 0) {
		//cout << "Pagina: " << actual->pagina << " PR: " << actual->PageRank << " Enlaces: " << actual->enlaces << endl;
		actual = actual->abajo;
	}
}

bool Case1 = true;
bool Case2 = true;
bool Case3 = false;
bool Case4 = false;
void ListaEnlazada::CalcularPR(NodoPagina* page, int iteracciones) {
	if (iteracciones == 400 && page == nullptr) {
		Ordenar();
		return;
	}
	if (page == nullptr) {
		iteracciones = iteracciones + 1;
		Case2 = false;
		Case3 = true;
		page = primero;
	}
	double PR = 0;
	NodoPagina* actual = primero;
	if (Case3) {
		page = primero;
		NodoPaginaRedirect* tmp;
		while (actual != 0) {
			actual = actual->abajo;
			if (actual == 0) {
				break;
			}
			tmp = actual->siguiente;
			while (tmp != 0) {
				if (page->pagina == tmp->pagina) {
					PR += (double)ExtraerPR(actual->pagina) / actual->enlaces;
				}
				tmp = tmp->siguiente;
			}
		}
		page->PageRank = 0.15 + 0.85 * (PR);
		Case4 = true;
		Case3 = false;
	}
	else if (Case4) {
		NodoPaginaRedirect* tmp = nullptr;
		while (actual != 0) {
			if (actual->pagina == page->pagina) {
				actual = actual->abajo;
			}
			if (actual == nullptr) {
				break;
			}
			if (actual->siguiente != nullptr) {
				tmp = actual->siguiente;
			}
			while (tmp != 0) {
				if (page->pagina == tmp->pagina) {
					PR += (double)ExtraerPR(actual->pagina) / actual->enlaces;
				}
				tmp = tmp->siguiente;
			}
			actual = actual->abajo;
		}
		page->PageRank = 0.15 + 0.85 * (PR);
	}
	if (Case1) {
		page = primero;
		NodoPaginaRedirect* tmp;
		while (actual != 0) {
			actual = actual->abajo;
			if (actual == 0) {
				break;
			}
			tmp = actual->siguiente;

			while (tmp != 0) {
				if (page->pagina == tmp->pagina) {
					PR += (double)1 / actual->enlaces;
				}
				tmp = tmp->siguiente;
			}
		}
		page->PageRank = 0.15 + 0.85 * (PR);
		Pr.push_back(page);
		Case1 = false;
	}
	else if (Case2) {
		NodoPaginaRedirect* tmp = nullptr;
		while (actual != 0) {
			if (actual->pagina == page->pagina) {
				actual = actual->abajo;
			}
			if (actual == nullptr) {
				break;
			}
			if (actual->siguiente != nullptr) {
				tmp = actual->siguiente;
			}
			while (tmp != 0) {
				if (page->pagina == tmp->pagina) {
					PR += 1 / (double)actual->enlaces;
				}
				tmp = tmp->siguiente;
			}
			actual = actual->abajo;

		}
		page->PageRank = 0.15 + 0.85 * (PR);
		Pr.push_back(page);
	}
	CalcularPR(page->abajo, iteracciones);
}

void ListaEnlazada::ArchivoPr() {
	ofstream filePr("PaginasWeb.html", ios::app);
	if (!filePr) {
		cout << "error de apertura en archivo" << endl;
		return;
	}
	for (int i = 0; i < Pr.size(); i++) {

		filePr << "Pagina: " << Pr[i]->pagina << "PR: " << Pr[i]->PageRank << "\n";
		//cout << "Pagina: " << Pr[i]->pagina << " PR: " << Pr[i]->PageRank << endl;
	}

} 

double ListaEnlazada::ExtraerPR(string pagina) {
	for (int i = 0; i < Pr.size(); i++) {
		if (Pr[i]->pagina == pagina) {
			return Pr[i]->PageRank;
		}
	}
	return 0;
}

void ListaEnlazada::Ordenar() {
	std::sort(Pr.begin(), Pr.end(), [](const NodoPagina* a, const NodoPagina* b) { return (a->PageRank > b->PageRank); });
	//std::sort (primero,primero + 1000,[](NodoPagina* a,NodoPagina* b) { return a->PageRank > b->PageRank; });
   //std::sort (Pr.begin (),Pr.end ());
	for (int i = 0; i < Pr.size(); i++) {
		//archivo << "Pagina: " << ordenar[i]->link << " PR: " << ordenar[i]->Pr << endl;
		cout << "<h2>Pagina: " << Pr[i]->pagina << " PR: " << Pr[i]->PageRank << "</h2>" << endl;
		cout << "<a href=\"" << Pr[i]->pagina << "\"> " << Pr[i]->pagina << " </a>" << endl;
	}
}

