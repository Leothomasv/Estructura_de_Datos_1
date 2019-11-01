#include "Archivos.h"
#include <fstream>




void functions::lecturaHTML(string archivo) {

	ifstream file(archivo);
	string text1 = "href";
	string text;

	string direccion;
	string html = ".html";
	string delimiter = "\"";
	string token;
	string PaginaPrincipal = archivo;

	string temporal;

	if (!file) {
		cout << "Fallo de archivo";
		exit(1);
	}

	//pagina principal
	cout << "{" << PaginaPrincipal << "}->";

	while (!file.eof()) {

         getline(file, text);

		if (text.find(text1) != string::npos) {


			for (int i = 0; i < text.size(); i++) {

				direccion += text[i];
			}

			size_t pos = 0;
			std::string token;
			while ((pos = direccion.find(delimiter)) != std::string::npos) {
				token = direccion.substr(0, pos);
				direccion.erase(0, pos + delimiter.length());
				if (token.find(html) != string::npos)
				{
					//std::cout << token << std::endl;
					direccion = token;

				}
			}


			cout << "{" << direccion << "}->";
			direccion = "";
		}
	}


			


		
			
		
		
	
}


//if (text[i] == (char)34) {
//	verificarNombre++;
//}
//
//if (verificarNombre == 1) {
//	direccion += text[i];
//}
//
//if (verificarNombre == 2) {
//	cout << direccion << endl;
//	verificarNombre = 0;
//	text1 = "href";
//}