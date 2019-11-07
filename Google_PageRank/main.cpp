#include "Archivos.h"
#include "ListaEnlazada.h"
#include <conio.h>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	functions F;
	ListaEnlazada List;

	/*F.lecturaHTML("google.html",0);
	F.lecturaHTML("facebook.html", 0);
	F.lecturaHTML("instagram.html", 0);*/

	F.findKeywords(argv[1]);
	//cout << F.lista.extraerRepetidos ("facebook.html");
	F.lista.LimpiarLista();
	//F.lista.imprimirLista ();
	F.lista.ImprimirPR();

	

}