#include "PlanEstudio.h"

PlanEstudio::PlanEstudio(): raiz(0) {}

bool PlanEstudio::estaVacio() {

	return raiz == 0;
}

materia* PlanEstudio::buscar(int codigoPadre) {

	return buscarRec(raiz, codigoPadre);
}

materia* PlanEstudio::buscarRec(materia* raiz, int codigoPadre) {
	if (raiz == 0) 
		return 0;

	if (raiz->codigo == codigoPadre) 
		return raiz;
	
	for (int i = 0; i < raiz->cantiHijos; i++) {

		materia* tmp = buscarRec(raiz->hijos[i], codigoPadre);
		if (tmp != 0)
			return tmp;
	}
	return 0;
}

void PlanEstudio::imprimir() {
	imprimirRec(raiz);
}

void PlanEstudio::imprimirRec(materia* raiz) {
	if (raiz == 0) {
		return;
	}

	cout << "Materia { codigo: " << raiz->codigo << ", Nombre: " << raiz->nombre << "}"<< endl;

	for (int i = 0; i < raiz->cantiHijos; i++) {
		imprimirRec(raiz->hijos[i]);
	}
}

void PlanEstudio::agregarMateria(int codigo, const char* nombre, int uv, int CodigoPadre) {

	materia* nueva = new materia(codigo, nombre, uv);

	if (estaVacio()) {
		raiz = nueva;
		return;
	}

	materia* padre = buscar(CodigoPadre);

	if (padre == 0) {
		cout << "Codigo de clase requisisto incorrecto!";
		delete nueva;
		return;
	}

	//crear copia de hijos
	materia** tmpHijos = new materia * [padre->cantiHijos +1]; //declarando un arreglo de apuntadores
	for (int i = 0; i < padre->cantiHijos; i++) {
		tmpHijos[i] = padre->hijos[i];
	}
	tmpHijos[padre->cantiHijos] = nueva; 

	if (padre->cantiHijos != 0) {
		delete padre->hijos;
	}

	padre->cantiHijos++;

	padre->hijos = tmpHijos;

	//cout << "Materia Ingresada!";
}