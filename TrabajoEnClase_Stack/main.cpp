#include "StackNode.h"
#include<iostream>

using namespace std;

int main() {

	Stack<int>* numero = new Stack<int>;

	numero->push(8);
	numero->push(5);
	numero->push(2);
	numero->push(0);
	numero->push(1);
	numero->push(9);

	numero->imprimir();

	numero->pop();
	cout << "Impresion despues del pop\n";
	numero->imprimir();


	cout<< "Primero numero de la lista: "<< numero->peek();

}