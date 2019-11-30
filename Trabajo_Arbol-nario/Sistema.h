#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
using namespace std;

enum File_Type { FILE, DIRECTORY};
class FileEntry {
private:
	string nombre;
	File_Type tipo;
public:
	File_Type getTipo();



};

class File : public FileEntry {
private:
	string extension;
	int bytes;
public:




};

class Directory :public FileEntry {
private:
	FileEntry** hijos;
	int cantHijos;
public:

	



};

class FileSystem {
private:
	Directory* raiz;

public:
	void buscar(Directory* raiz, string archivo);
	int obtenerTamano(Directory* raiz);
	



};



#endif // !SISTEMA_H
