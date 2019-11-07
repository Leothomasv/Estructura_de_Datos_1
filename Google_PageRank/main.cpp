#include "Archivos.h"
#include "ListaEnlazada.h"
#include <conio.h>
#include <iostream>
using namespace std;


int main() {

	functions F;
	ListaEnlazada List;

	/*F.lecturaHTML("google.html",0);
	F.lecturaHTML("facebook.html", 0);
	F.lecturaHTML("instagram.html", 0);*/

	F.findKeywords("Videos");
	cout << F.lista.extraerRepetidos("facebook.html");
	F.lista.LimpiarLista();
	F.lista.imprimirLista();
	//F.findKeywords("Music");
	

	



}