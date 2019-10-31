#pragma once
#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>

using namespace std;

template <class T> 

struct  StackNode
{
	T dato;
	StackNode* siguiente;

};
	
template <class T>

class Stack {

private:
	StackNode<T>* primero;
public:
	Stack(void);
	bool estaVacia(void);   
	void push(const T&);
	void pop(void);
	const T& peek(void);
	void imprimir();
};


template <class T>
Stack<T>::Stack():Stack<T>::primero(nullptr) {}

template <class T>
bool Stack<T>::estaVacia(void) {
	return primero == nullptr;
}

template <class T>
void Stack<T>::push(const T& dato) {
	StackNode<T>* nuevo = new StackNode<T>;

	nuevo->siguiente = nullptr;
    nuevo->dato = dato;

	if (estaVacia()) {
		primero = nuevo;
	}
	else {
		nuevo->siguiente = primero;
		primero = nuevo;
	}
}

template <class T>
void Stack<T>::pop(void) {
	if (!estaVacia()) {

		StackNode<T>* borrar = primero;
		primero = primero->siguiente;
		delete borrar;
	}
}

template <class T>
const T& Stack<T>::peek(void) {
	StackNode<T>* nuevo = primero;
	return nuevo->dato;
}

template <class T>
void Stack<T>::imprimir(void) {
	StackNode<T>* actual = primero;

	while (actual != nullptr) {
		cout << "{"<< actual->dato << "}" << endl;
		actual = actual->siguiente;
	}
}
#endif // !STACKNODE_H


