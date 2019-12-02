#include "FileSystem.h"

FileEntry* FileSystem::Buscar(string name)
{
	if (raiz == 0) {
		return 0;
	}

	if (raiz->nombre == name)
		return raiz;

	//saber el tipo archivo/directorio
	for (int i = 0; i < raiz->cantHijos; i++)
	{
		FileEntry* temporal = raiz->hijos[i];
		if (temporal->tipo == DIRECTORIO) {
			Directory* TemporalDirectory = (Directory*)temporal;
			return BuscarRec(TemporalDirectory, name);
		}
	}

	return 0;


}

FileEntry* FileSystem::BuscarRec(Directory* raiz, string name)
{
	if (raiz == 0) {
		return 0;
	}

	if (raiz->nombre == name)
		return raiz;

	//saber el tipo archivo/directorio
	for (int i = 0; i < raiz->cantHijos; i++)
	{
		FileEntry* temporal = raiz->hijos[i];
		if (temporal->tipo == DIRECTORIO) {
			Directory* TemporalDirectory = (Directory*)temporal;
			return BuscarRec(TemporalDirectory, name);
		}
	}
	return 0;
}

int FileSystem::obtenerTamano(string name) {

	FileEntry* archivo = Buscar(name);

	if (archivo->tipo == DIRECTORIO) {
		Directory* tmp = (Directory*)archivo;
		return obtenerTamanoRec(tmp);
	}
}

int FileSystem::obtenerTamanoRec(Directory* raiz) {

	int tamano = 0;
	for (int i = 0; i < raiz->cantHijos; i++)
	{
		FileEntry* tmp = raiz->hijos[i];

		if (tmp->tipo == ARCHIVO) {
			File TemporalFile = *(File*)tmp;
			tamano += TemporalFile.bytes; //se le suman la cantidad de bytes del archivo
		}
		else {
			Directory* TemporalDir = new Directory(tmp->nombre);
			tamano += obtenerTamanoRec(TemporalDir);
		}
	}
	return tamano;
}

void FileSystem::CrearCarpeta(string nombre, string direccion)
{
	Directory* nuevo = new Directory();
	nuevo->tipo = DIRECTORIO;
	nuevo->nombre = nombre;

	if (raiz == 0) {
		raiz = nuevo;
	}
	else {
		//castear buscar a directory
		Directory* guardar = (Directory*)Buscar(direccion);
		FileEntry** hijos = new FileEntry * [guardar->cantHijos + 1];

		for (int i = 0; i < guardar->cantHijos; i++)
		{
			hijos[i] = guardar->hijos[i];
		}

		hijos[guardar->cantHijos] = nuevo;
		guardar->hijos = hijos;

		guardar->cantHijos++;
	}

}

void FileSystem::CrearArchivo(string direccion, string nombre, string extension, int tamano)
{

	File* nuevo = new File(nombre, extension);
	nuevo->tipo = ARCHIVO;
	nuevo->bytes = tamano;

	Directory* guardar = (Directory*)Buscar(direccion);
	if (guardar != 0) {

		FileEntry** hijos = new FileEntry * [guardar->cantHijos + 1];

		for (int i = 0; i < guardar->cantHijos; i++)
		{
			hijos[i] = guardar->hijos[i];
		}

		hijos[guardar->cantHijos] = nuevo;
		guardar->hijos = hijos;

		guardar->cantHijos++;

	}
	else {
		cout << "No existe carpeta" << endl;
	}


}

void FileSystem::imprimir()
{
	cout << "<<Carpeta>>" << raiz->nombre << endl;
	for (int i = 0; i < raiz->cantHijos; i++)
	{
		if (raiz->hijos[i]->tipo == ARCHIVO)
		{
		    cout << "Archivo: " << raiz->hijos[i]->nombre <<endl;
		}
	}

	for (int i = 0; i < raiz->cantHijos; i++)
	{
		if (raiz->hijos[i]->tipo == DIRECTORIO)
		{
			imprimirRec((Directory*)raiz->hijos[i]);

		}

	}

}

void FileSystem::imprimirRec(Directory* raiz)
{
	cout << "<<Carpeta>>" << raiz->nombre << endl;
	for (int i = 0; i < raiz->cantHijos; i++)
	{
		if (raiz->hijos[i]->tipo == ARCHIVO)
		{
			cout << "Archivo: " << raiz->hijos[i]->nombre << endl;
		}
	}

	for (int i = 0; i < raiz->cantHijos; i++)
	{
		if (raiz->hijos[i]->tipo == DIRECTORIO)
		{
			imprimirRec((Directory*)raiz->hijos[i]);

		}

	}
}
