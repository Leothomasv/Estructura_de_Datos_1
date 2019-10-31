#include "Archivos.h"
#include <fstream>



void functions::lecturaHTML(string archivo) {

	ifstream file(archivo);
	string text1 = "href";
	string text;
	string direccion;


	int verificarNombre = 0;
	int cont = 0;
	size_t pos;


	if (!file) {
		cout << "Fallo de archivo";
		exit(1);
	}

	while (!file.eof()) {

		getline(file, text);
		pos = text.find(text1);

		if (pos != string::npos) {
			getline(file, text);
			for (int i = 1; i < text.size(); i++) {


				if (verificarNombre == 1) {
					direccion += text[i];
					
				}

				if (text[i] == (char)34 ) {
					verificarNombre++;
				}

				
				
			}
			//funcion strtok es para eliminar un caracter 
			cout << direccion << endl;
			    direccion = "";
		}
		
	
	
	}
	

}
