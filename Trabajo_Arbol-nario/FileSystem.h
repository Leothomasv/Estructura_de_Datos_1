#pragma once
#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "FileEntry.h"
#include "Directory.h"
#include "File.h"



class FileSystem {
private:
	Directory* raiz = 0;

public:
	 FileEntry* Buscar(string name);
	 FileEntry* BuscarRec(Directory* raiz, string name);
	 int obtenerTamano(string name);
	 int obtenerTamanoRec(Directory* raiz);

	 void CrearCarpeta(string nombre, string direccion);
	 void CrearArchivo(string direccion, string nombre, string extension, int tamano);

	 void imprimir();
	 void imprimirRec(Directory* raiz);

};




#endif // !FILESYSTEM_H

