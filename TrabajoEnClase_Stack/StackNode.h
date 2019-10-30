#pragma once
#ifndef STACKNODE_H
#define STACKNODE_H

template <class T> 

struct  StackNode
{
	T dato;
	StackNode* siguiente;

	StackNode(T dato, siguiente nullptr) {

		dato = 0;
		siguiente = nullptr;
	}

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
};
#endif // !STACKNODE_H


