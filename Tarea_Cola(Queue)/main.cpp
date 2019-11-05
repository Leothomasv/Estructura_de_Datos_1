#include "Cola.h"



int main() {

	Cola<int>* lista = new Cola<int>;

	//maximo 3 palabras
	lista->Enqueue(1);
	lista->Enqueue(2);
	lista->Enqueue(3);
	lista->Enqueue(4);

	//lista->Dequeue();

	cout << lista->Peek();
	return 0;
}