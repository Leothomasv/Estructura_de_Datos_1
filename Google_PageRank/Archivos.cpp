#include "Archivos.h"
#include <fstream>
#include <vector>
#include "ListaEnlazada.h"


//variables de prueba
string href1, href2, href3, href4;
int contador = 0;

bool primeroX = true;
bool existe = true;
vector<string> hrefs;
bool prueba = false;
void functions::lecturaHTML(string archivo,int posicion) {

	ifstream file (archivo);
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
	cout << "{" << PaginaPrincipal << "}->";
	if (primeroX)
	{
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
				if (token.find(html) != string::npos)
				{
					direccion = token;
					if (existe)
					{
						if (prueba)
						{
							lista.agregarAbajo(archivo);
							prueba = false;
						}
						lista.agregarSiguiente(direccion);
						hrefs.push_back(direccion);
						token = "";
						contador++;
					}
					else {
						lista.agregarSiguiente(direccion);
					}
					
				}
			}
			cout << "{" << direccion << "}->";
			direccion = "";
			token = "";
		}

	}
	file.close();
	existe = false;


	cout << endl;
	if (hrefs.size()==posicion)
	{
		prueba = true;
		hrefs.clear();
		existe = true;
		return;
	}
	lista.agregarAbajo(hrefs[posicion]);
	lecturaHTML(hrefs[posicion], posicion+1);
	cout << endl;
	
}

//void functions::buscarHref(string archivo) {
//
//	ifstream file(archivo);
//	string text1 = "href";
//	string text;
//
//	string direccion;
//	string html = ".html";
//	string delimiter = "\"";
//	string token;
//	string PaginaPrincipal = archivo;
//
//
//	//pagina principal
//	cout << endl;
//	cout << "{" << PaginaPrincipal << "}->";
//
//	while (!file.eof()) {
//
//		getline(file, text);
//
//		if (text.find(text1) != string::npos) {
//
//			for (int i = 0; i < text.size(); i++) {
//				direccion += text[i];
//			}
//
//			size_t pos = 0;
//			std::string token;
//			while ((pos = direccion.find(delimiter)) != std::string::npos) {
//				token = direccion.substr(0, pos);
//				direccion.erase(0, pos + delimiter.length());
//
//				if (token.find(html) != string::npos)
//				{
//					direccion = token;
//				}
//			}
//
// 			cout << "{" << direccion << "}->";
//			lista.agregarSiguiente(direccion);
//			direccion = "";
//		}
//
//	}
//	file.close();
//
//
//}

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

void functions::findKeywords(string pagina) {

	string PaginasWeb[7] = {"google.html","amazon.html","facebook.html","instagram.html","twitter.html","whatsapp.html","youtube.html"};
	string text;
	for (int i = 0; i < 7; i++) {
		ifstream file(PaginasWeb[i]);
		if (!file.is_open())
		{
			return;
		}
		else {
			while (!file.eof()) {
				getline(file, text);
				if (text.find(pagina) != string::npos) {

					cout << "Pagina: " << PaginasWeb[i];

				}
			}
			file.close();

		}
		

	}
}

void functions::calcularPR(){


}


