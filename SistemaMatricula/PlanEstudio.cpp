#include "PlanEstudio.h"
#include "Estudiantes.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <regex>
#include <algorithm>
//variables
vector<string> planes;

PlanEstudio::PlanEstudio() {
	raiz = 0;
}
void PlanEstudio::agregarMateria(string codigo, string nombre, int uv, string CodigoPadre,string des) {
	materia* nueva = new materia(codigo, nombre, uv, CodigoPadre, des);
	if (estaVacio()) {
		materia** tmpHijos = new materia * [1];
		tmpHijos[0] = nueva;
		raiz = tmpHijos;
		raices++;
		return;
	}
	if (CodigoPadre == "0") {
		raiz[raices] = nueva;
		raices++;
		return;
	}
	materia** padre = buscar(CodigoPadre);
	if (padre == nullptr) {
		cout << "Codigo de clase requisisto incorrecto!";
		delete nueva;
		return;
	}
	materia** tmpHijos = new materia * [(*padre)->cantiHijos + 1]; //declarando un arreglo de apuntadores
	for (int i= 0; i < (*padre)->cantiHijos; i++) {
		tmpHijos[i] = (*padre)->hijos[i];
	}
	tmpHijos[(*padre)->cantiHijos] = nueva;
	(*padre)->cantiHijos++;
	(*padre)->hijos = tmpHijos;
}

bool PlanEstudio::estaVacio() {
	return raiz==0;
}
materia** PlanEstudio::buscar(string requisito) {
	for (int i = 0; i < raices; i++)
	{
		return buscarRec(&raiz[i], requisito);
	}
}

materia** PlanEstudio::buscarRec(materia** raiz, string requisito) {
	if (raiz == 0) {
		return 0;
	}
	if ((*raiz)->codigo==requisito)
	{
		return raiz;
	}
	for (int i = 0; i < (*raiz)->cantiHijos; i++) {
		materia**a=buscarRec(&(*raiz)->hijos[i],requisito);
		if (a!=0)
		{
			return a;
		}
	}
	return 0;
}

void PlanEstudio::imprimir() {
	for (int i = 0; i < raices; i++) {
		imprimirRec(raiz[i]);
	}
}

void PlanEstudio::imprimirRec(materia* raiz) {
	if (raiz == 0) {
		return;
	}
	cout << "Materia { codigo: " << raiz->codigo << ", Nombre: " << raiz->nombre << " Padre: "<<raiz->requisito<<"}" << endl;
	for (int i = 0; i < raiz->cantiHijos; i++) {
		imprimirRec(raiz->hijos[i]);
	}
}



void PlanEstudio::crearPensum(string NombreArchivo) {
	planes.push_back(NombreArchivo);
	ofstream filePensum(NombreArchivo, ios::out | ios::app | ios::binary);
	materiaFile nuevo;
	for (int i = 0; i <6; i++) {
		cout << "<>><><><><><><><>><><><><><>><><><>" << endl;
		cout << "Ingrese codigo de materia:";
		cin >> nuevo.codigo;
		cout << "Ingrese nombre de materia:";
		cin >> nuevo.nombre;
		cout << "Ingrese UV de materia:";
		cin >> nuevo.uv;
		cout << "Ingrese requisito: ";
		cin >> nuevo.requisito;
		cin.ignore();
		cout << "Ingrese desbloqueo: ";
		cin.getline(nuevo.desbloqueo, 45);
		cout << "<>><><><><><><><>><><><><><>><><><>" << endl;
		filePensum.write(reinterpret_cast<const char*>(&nuevo), sizeof(materiaFile));
	}
	filePensum.close();
	cout << "<<PENSUM CREADO EXITOSAMENTE>>" << endl;
	//leerPensum(NombreArchivo);
}   

void PlanEstudio::leerVector() {
	for (auto const& i : planes) {
		std::cout << i << "\n";
	}
 }


void PlanEstudio::leerPensum() {
	Estudiantes e;
	ifstream filePensum(e.obtenerCarrera(), ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);

	materiaFile lectura;
	string codigo; string nombre; int uv; string requisito;
	string des;

	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(materiaFile));
	while (!filePensum.eof()) {

		//cout << "Codigo: " << lectura.codigo << " Nombre: " << lectura.nombre << " UV: " << lectura.uv << " Requisitos: "<<lectura.requisito << " Desbloqueo: "<<lectura.desbloqueo<<endl;

		codigo = lectura.codigo;  nombre = lectura.nombre; uv = lectura.uv; requisito = lectura.requisito; des = lectura.desbloqueo;

   		agregarMateria(codigo, nombre, uv, requisito,des);
		//va sumando el total de UV de todo el pensum 
		//nuevo.TotalUV += lectura.uv;
	
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(materiaFile));

	}
	filePensum.close();

}
vector<materia*>clasesD;
void PlanEstudio::obtenerClasesDisponibles() {
	cout << "\n";
	Estudiantes e;

	int posicion = 0;
	for (int i = 0; i < raices; i++)
	{
		if (!claseAprobada(raiz[i]->codigo)) {
			clasesD.push_back(raiz[i]);
		} 
		else {
			recorrer(&raiz[i]);
		}
	}
	//esto borra las repetidas
	auto comp = [](const materia* lhs, const materia* rhs) {return lhs->codigo < rhs->codigo; };
	sort(clasesD.begin(), clasesD.end(), comp);

	auto comp1 = [](const materia* lhs, const materia* rhs) {return lhs->codigo == rhs->codigo; };
	auto last = std::unique(clasesD.begin(), clasesD.end(), comp1);
	clasesD.erase(last, clasesD.end());
	for (int i = 0; i < clasesD.size(); i++)
	{
		cout << i << " Codigo: " << clasesD[i]->codigo << " nombre:" << clasesD[i]->nombre << " uv: " << clasesD[i]->uv << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Ingrese Clase: ";
		cin >> posicion;
		if (posicion==-1)
		{
			clasesD.clear();
			return;
		}
		e.matricular(clasesD[posicion]->codigo, clasesD[posicion]->nombre, clasesD[i]->uv, 0);
	}
	clasesD.clear();

}
vector<string>clasesP;

void PlanEstudio::recorrer(materia**raiz) {
	if (raiz == 0) {
		return;
	}

	stringstream ss((*raiz)->desbloqueo);
	string word;
	int contador = 0;
	while (ss >> word) {
		Rec(word);
		for (int i = 0; i < clasesP.size(); i++)
		{
			if (claseAprobada(clasesP[i])) {
				contador++;
			}
		}
		if (contador==clasesP.size())
		{
			if (word!="0")
			{
				materia** obtener = buscar(word);
				if (!claseAprobada(word))
				{
					clasesD.push_back(*(obtener));

				}
			}
		
		}
		contador = 0;
		clasesP.clear();
	}
	for (int i = 0; i < (*raiz)->cantiHijos; i++) {
		recorrer(&(*raiz)->hijos[i]);
	}

}
void PlanEstudio::Rec(string codigo) {
	for (int i = 0; i < raices; i++)
	{
		padres(&raiz[i], codigo);
	}

}
void PlanEstudio::padres(materia** raiz,string codigo) {
	if (raiz==0)
	{
		return ;
	}
	stringstream ss((*raiz)->desbloqueo);
	string word;
	int contador = 0;
	while (ss >> word) {
		if (codigo.find(word) != std::string::npos && word!="0") {
			clasesP.push_back((*raiz)->codigo);
		}
	}
	
	for (int i = 0; i < (*raiz)->cantiHijos; i++) {
		padres(&(*raiz)->hijos[i],codigo);
	}
}
void PlanEstudio::obtenerHistorialAcademico() {
	ifstream filePensum("HistorialAcademico.dat", ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);

	MateriMatriculada lectura;
	int Uv = 0;
	float resultado = 0;
	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	cout << "\n";
	cout << "<<RENDIMIENTO ACADEMICO>>" << endl;
	while (!filePensum.eof()) {
		Uv += lectura.uv;
		resultado += (lectura.nota) * lectura.uv;
		cout << "Codigo: " << lectura.codigo << " Nombre: " << lectura.nombre << " UV: " << lectura.uv << " Nota: " << lectura.nota << endl;
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	}
	resultado = (float)(resultado / Uv);
	cout << "\nPROMEDIO ACADEMICO: " << resultado;
	cout << "\n\n";
	filePensum.close();
}
bool PlanEstudio::claseAprobada(string codigo) {
	ifstream filePensum("HistorialAcademico.dat", ios::in | ios::binary);
	if (!filePensum)
	{
		return false;
	}
	filePensum.seekg(0, ios::beg);

	MateriMatriculada lectura;

	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	while (!filePensum.eof()) {
		if (lectura.codigo==codigo&&lectura.nota>=60)
		{
			return true;
		}
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	}
	filePensum.close();
	return false;
}
void PlanEstudio::ModificarNota(string codigo,int nota) {
	fstream archivoE("HistorialAcademico.dat", ios::in | ios::out | ios::binary);
	//fstream leer y ir modificando el valor
	if (!archivoE) {
		cout << "Error de lectura en el archivo";
	}
	archivoE.seekg(0, ios::beg);
	MateriMatriculada lectura;
	archivoE.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	int posicionregistro = 0;
	while (!archivoE.eof()) {
		if (strcmp(lectura.codigo, codigo.c_str()) == 0 && lectura.nota == 0) {
			lectura.nota = nota;
			archivoE.seekp(posicionregistro * sizeof(MateriMatriculada), ios::beg);
			archivoE.write(reinterpret_cast<const char*>(&lectura), sizeof(MateriMatriculada));
			archivoE.close();
			return;
		}
		posicionregistro++;
		archivoE.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	}
	archivoE.close();
}

