#include "Grafo.h"

int main() {
	Grafo nuevo;

	nuevo.agregarVertice('A');
	nuevo.agregarVertice('B');
	nuevo.agregarVertice('C');
	nuevo.agregarVertice('D');
	
	// agrear aristas
	nuevo.agregarArista('A', 'B', 4);
	nuevo.agregarArista('A', 'C', 6);
	nuevo.agregarArista('D', 'A', 2);
	nuevo.agregarArista('D', 'C', 8);

	nuevo.imprimir();

}