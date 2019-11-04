#include "Archivos.h"
#include <fstream>
#include "ListaEnlazada.h"

//variables de prueba
string href1, href2, href3, href4;
int contador = 0;

bool primeroX = true;
void functions::lecturaHTML(string archivo) {

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
					//std::cout << token << std::endl;
 					direccion = token;
					lista.agregarSiguiente(direccion);
					token = "";
					contador++;

				}
			}
			cout << "{" << direccion << "}->";
			//agregar(direccion)
		
			
			//prueba(funciona)
			if (contador == 1) {
				href1 = direccion;
				direccion = "";
			}
			else if (contador == 2) {
				href2 = direccion;
				direccion = "";
			}
			else if (contador == 3) {
				href3 = direccion;
				direccion = "";
			}
			else if (contador == 4) {
				href4 = direccion;
				direccion = "";
			}
		}

	}
	file.close();
	switch (contador)
	{
	case 1:
		buscarHref(href1);
		break;
	case 2:
		buscarHref(href1);buscarHref(href2);
		break;
	case 3:
		lista.agregarAbajo(href1);
		buscarHref(href1);
		lista.agregarAbajo(href2);
		buscarHref(href2);
		lista.agregarAbajo(href3);
		buscarHref(href3);
		break;
	case 4:
		buscarHref(href1);buscarHref(href2);buscarHref(href3);buscarHref(href4);
		break;
	default:
		break;
	}

	cout << endl;
	cantidadHref(PaginaPrincipal); cantidadHref(href1); cantidadHref(href2); cantidadHref(href3); cantidadHref(href4);
	cout << endl;
	
}

void functions::buscarHref(string archivo) {

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
					direccion = token;
				}
			}

 			cout << "{" << direccion << "}->";
			lista.agregarSiguiente(direccion);
			direccion = "";
		}

	}
	file.close();


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

void functions::findKeywords() {

	string PaginasWeb[7] = {"google.html","amazon.html","facebook.html","instagram.html","twitter.html","whastapp.html",""};


}

void functions::calcularPR(){


}


