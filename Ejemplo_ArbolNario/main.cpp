#include "PlanEstudio.h"

int main() {

	PlanEstudio nuevo;

	nuevo.agregarMateria(100, "Introduccion al algebra", 4, 0);
	nuevo.agregarMateria(101, "algebra", 4, 100);
	nuevo.agregarMateria(102, "Introduccion a la computacion", 4, 100);
	nuevo.agregarMateria(103, "Programacion 1", 4, 102);

	nuevo.imprimir();




}