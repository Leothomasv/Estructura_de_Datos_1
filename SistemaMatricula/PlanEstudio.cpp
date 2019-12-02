#include "PlanEstudio.h"

PlanEstudio::PlanEstudio() : raiz(0) {}

bool PlanEstudio::estaVacio() {

	return raiz == 0;
}

materia* PlanEstudio::buscar(string requisito) {

	return buscarRec(raiz, requisito);
}

materia* PlanEstudio::buscarRec(materia* raiz, string requisito) {
	if (raiz == 0)
		return 0;

	if (raiz->codigo == requisito)
		return raiz;

	for (int i = 0; i < raiz->cantiHijos; i++) {

		materia* tmp = buscarRec(raiz->hijos[i], requisito);
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

	cout << "Materia { codigo: " << raiz->codigo << ", Nombre: " << raiz->nombre << "}" << endl;

	for (int i = 0; i < raiz->cantiHijos; i++) {
		imprimirRec(raiz->hijos[i]);
	}
}

void PlanEstudio::crearPensum(string NombreArchivo) {

	ofstream filePensum (NombreArchivo, ios::out ||ios::app || ios::binary);

	//string codigo; string nombre; int uv; string requisito;
	materia nuevo;
	
	for (int i = 0; i < 2; i++) { 
		cout << "<>><><><><><><><>><><><><><>><><><>"<<endl;
		cout << "Ingrese codigo de materia: ";
		cin >> nuevo.codigo;
		cout << "Ingrese nombre de materia: ";
		cin >> nuevo.nombre;
		cout << "Ingrese UV de materia: ";
		cin >> nuevo.uv;
		cout << "Ingrese requisito de materia: ";
		cin >> nuevo.requisito;
		cout << "<>><><><><><><><>><><><><><>><><><>"<<endl;
		
		//agregarMateria(codigo, nombre, uv, requisito);
		
		//filePensum << "Codigo: " << codigo << " Nombre: " << nombre << " UV: " << uv << " Requisito: " << requisito <<"\n";
		//binario
		filePensum.write(reinterpret_cast<const char*>(&nuevo), sizeof(materia));

	}
	filePensum.close();

	leerPensum(NombreArchivo);
}


void PlanEstudio::leerPensum(string nomnbrearchivo) {
	string codigo; string nombre; int uv; string requisito;

	ifstream filePensum(nomnbrearchivo, ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);

	materia lectura;

	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(materia));


	while (filePensum.eof()) {

		codigo = lectura.codigo;
		nombre = lectura.nombre;
		uv = lectura.uv;
		requisito = lectura.requisito;

		agregarMateria(codigo, nombre, uv, requisito);

		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(materia));

	}
	filePensum.close();

}

void PlanEstudio::agregarMateria(string codigo, string nombre, int uv, string requisito) {

	materia* nueva = new materia(codigo, nombre, uv, requisito);

	if (estaVacio()) {
		raiz = nueva;
		return;
	}

	materia* padre = buscar(requisito);

	if (padre == 0) {
		cout << "!!CLASE NO TIENE REQUISITOS!!\n";
		delete nueva;
		return;
	}

	//crear copia de hijos
	materia** tmpHijos = new materia * [padre->cantiHijos + 1]; //declarando un arreglo de apuntadores
	for (int i = 0; i < padre->cantiHijos; i++) {
		tmpHijos[i] = padre->hijos[i];
	}
	tmpHijos[padre->cantiHijos] = nueva;

	if (padre->cantiHijos != 0) {
		delete padre->hijos;
	}

	padre->cantiHijos++;

	padre->hijos = tmpHijos;

	return;

}
