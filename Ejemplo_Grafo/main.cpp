#include "Grafo.h"

int main() {
	Grafo nuevo;

	nuevo.agregarVertice('A');
	nuevo.agregarVertice('B');
	nuevo.agregarVertice('C');
	nuevo.agregarVertice('D');
	
	// agrear aristas
	nuevo.agregarArista('A', 'B');
	nuevo.agregarArista('C', 'D');
	nuevo.agregarArista('B', 'C');
	nuevo.agregarArista('A', 'D');






	nuevo.imprimir();

}