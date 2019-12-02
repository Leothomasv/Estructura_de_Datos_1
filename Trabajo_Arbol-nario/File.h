#pragma once
#ifndef FILE_H
#define FILE_H
#include "FileEntry.h"

class File : public FileEntry {
public:
	File_Type tipo = ARCHIVO;
	string extension;
	double bytes;

	File() {};

	File(string name, string extension) {

	}

	File_Type getType() {
		return tipo;
	}

};





#endif // !FILE_H

