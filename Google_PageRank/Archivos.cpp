#include "Archivos.h"
#include <fstream>
#include <vector>
#include "ListaEnlazada.h"
#include <string>


bool primeroX = true;
bool existe = true;
vector<string> hrefs;
bool prueba = false;

vector<string> WebPages;

void functions::lecturaHTML(string archivo, int posicion) {

	ifstream file("C:\\Users\\leoth\\source\\repos\\Estructura_de_Datos_1\\Google_PageRank\\pages\\" + archivo);
	string text1 = "href";
	string text;

	string direccion;
	string html = ".html";
	string delimiter = "\"";
	string token;
	string PaginaPrincipal = archivo;



	if (!file.is_open()) {
		cout << "Fallo de archivo";
	}

	//pagina principal
	cout << endl;
	//cout << "{" << PaginaPrincipal << "}->";
	if (primeroX) {
		lista.agregar(archivo);
		primeroX = false;
	}
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
				if (token.find(html) != string::npos) {
					direccion = token;
					if (existe) {
						if (prueba) {
							lista.agregarAbajo(archivo);
							prueba = false;
						}
						lista.agregarSiguiente(direccion);
						hrefs.push_back(direccion);
						token = "";
					}
					else {
						lista.agregarSiguiente(direccion);
					}

				}
			}
			//cout << "{" << direccion << "}->";
			direccion = "";
			token = "";
		}

	}
	file.close();
	existe = false;


	cout << endl;
	if (hrefs.size() == posicion) {
		//lista.imprimirLista();
		prueba = true;
		hrefs.clear();
		existe = true;
		return;
	}
	lista.agregarAbajo(hrefs[posicion]);
	lecturaHTML(hrefs[posicion], posicion + 1);
	cout << endl;

}



int functions::cantidadHref(string pagina) {
	ifstream file(pagina);
	string text1 = "href";
	string text;
	string Pagina = pagina;
	int cantidad = 0;


	while (!file.eof()) {
		getline(file, text);

		if (text.find(text1) != string::npos) {
			cantidad++;
		}

	}
	file.close();

	/*cout << "===============================================" << endl;
	cout << Pagina << ": Cantidad de Href: " << cantidad << endl;
	cout << "===============================================" << endl;*/

	return cantidad;

}

void functions::findKeywords(string palabra) {
	list_dir();

	string text;
	for (int i = 0; i < WebPages.size(); i++) {

		string page = WebPages[i];
		ifstream file("C:\\Users\\leoth\\source\\repos\\Estructura_de_Datos_1\\Google_PageRank\\pages\\" + page);

		if (!file.is_open()) {
			return;
		}
		else {
			while (!file.eof()) {
				getline(file, text);
				if (text.find(palabra) != string::npos) {

					//cout << "Pagina: " << WebPages[i] << endl;
					lecturaHTML(WebPages[i], 0);
				}
			}
			file.close();

		}


	}
}

void functions::list_dir() {
	string direct = "C:\\Users\\leoth\\source\\repos\\Estructura_de_Datos_1\\Google_PageRank\\pages";

	DIR* directorio;
	struct dirent* elemento;
	string elem;
	if (directorio = opendir(direct.c_str())) {
		while (elemento = readdir(directorio)) {
			elem = elemento->d_name;
			if (elem != "." && elem != "..") {
				//cout << elem << endl;
				WebPages.push_back(elem);
			}
		}
	}
	closedir(directorio);
}


