#include "Archivos.h"
#include <fstream>

//variables de prueba
string href1, href2, href3, href4;
int contador = 0;


void functions::lecturaHTML(string archivo) {

	ifstream file (archivo);
	string text1 = "href";
	string text;

	string direccion;
	string html = ".html";
	string delimiter = "\"";
	string token;
	string PaginaPrincipal = archivo;


	//variables prueba
	string href1, href2, href3, href4;
	int contador = 0;


	if (!file.is_open()) {
		cout << "Fallo de archivo";
	}

	//pagina principal
	cout << endl;
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
					token = "";

				}
			}

			cout << "{" << direccion << "}->";
			
			//prueba(funciona)
			
			if (contador == 0) {
				href1 = direccion;
				contador++;
				direccion = "";
			}
			else if (contador == 1) {
				href2 = direccion;
				contador++;
				direccion = "";
			}
			else if (contador == 2) {
				href3 = direccion;
				contador++;
				direccion = "";
			}
			else if (contador == 3) {
				href4 = direccion;
				contador ++; //final
				direccion = "";
			}
		}
	}
	contador = 0;

	verificarHref(href1);
	verificarHref(href2);
	verificarHref(href3);
	verificarHref(href4);
}

void functions::verificarHref(string archivo) {

	ifstream file(archivo);
	string text1 = "href";
	string text;

	string direccion;
	string html = ".html";
	string delimiter = "\"";
	string token;
	string PaginaPrincipal = archivo;


	//pagina principal
	cout << endl;
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


