#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "FileEntry.h"


class Directory :public FileEntry {
public:
	File_Type tipo = DIRECTORIO;
	FileEntry** hijos;
	int cantHijos = 0;

	Directory() {}

	Directory(string nombre) {

	}

	File_Type getType() {
		return tipo;
	}


};


#endif // !DIRECTORY_h
