#pragma once
#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;


template < class T>
struct ColaNode {

	T dato;
	ColaNode* anterior;
	ColaNode* siguiente;

	ColaNode(T dato, ColaNode* siguiente, ColaNode* anterior) {
		this->dato = dato;
		this->anterior = anterior;
		this->siguiente = siguiente;
	}
};


template <class T>
class Cola {
private:

	ColaNode<T>* primero;
	ColaNode<T>* ultimo;
	int cantidad;


public:	
	Cola();
	void Enqueue(T);
	void Dequeue(void);
	bool isEmpty();
	bool isFull(void);
	const T &Peek(void);
};

template <class T>
Cola<T>::Cola() :primero(nullptr), ultimo(nullptr), cantidad(0) {
}

template<class T>
bool Cola<T>::isEmpty() {
	return primero == nullptr;
}

template<class T>
bool Cola<T>::isFull() {
	return cantidad < 4;
}

template <class T>
void Cola<T>::Enqueue(T dato) {

	ColaNode<T>* nuevo = new ColaNode<T>( dato, nullptr, nullptr);

	if (isFull()) {

		if (isEmpty()) {
			primero = nuevo;
			primero->siguiente = ultimo;
			ultimo = nuevo;
			cantidad++;
		}
		else {
			primero = nuevo;
			nuevo->anterior = ultimo;
			nuevo->siguiente = primero;
			ultimo->siguiente = nuevo;
			primero->anterior = nuevo;
			cantidad++;
		}

	}
}

template <class T>
void Cola<T>::Dequeue() {

	if (!isEmpty()) {

		ColaNode<T>* actual = primero;
		primero = primero->siguiente;
		ultimo->siguiente = primero;
		primero->anterior = ultimo;

		delete actual;
	}

}


template <class T>
const T& Cola<T>::Peek(void) {
	ColaNode<T>* actual = primero;
	return actual->dato;
}





#endif // !COLA_H
