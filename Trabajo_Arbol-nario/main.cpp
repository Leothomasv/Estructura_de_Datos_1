#include "File.h"
#include "Directory.h"
#include "FileSystem.h"

int main() {

	int OpcionPrincipal = 0;
	FileSystem F;
	//opcion 1
	string nombre;
	string extension;
	string carpeta;
	int tamano = 0;
	//opcion 2
	string  nombre1;
	string guardar1;
	//opcion 3
	string nombre2;


	do {

		cout << "------------MENU----------------\n";
		cout << "1. Agregar Archivo" << endl;
		cout << "2. Agregar Directorio" << endl;
		cout << "3. Ver tamaño del directorio o archivo" << endl;
		cout << "4. Imprimir" << endl;
		cout << "5. Salir" << endl;
		cout << "Ingrese la opcion: ";
		cin >> OpcionPrincipal;

		switch (OpcionPrincipal)
		{
		case 1:

			cout << "Ingrese nombre del archivo : ";
			cin >> nombre;
			cout << "Ingrese extension del archivo : ";
			cin >> extension;
			cout << "Ingrese tamaño del archivo : ";
			cin >> tamano;
			cout << "ingrese carpeta donde se guardara del archivo : ";
			cin >> carpeta;

			F.CrearArchivo(carpeta, nombre, extension, tamano);
			break;

		case 2:
			cout << "Ingrese nombre de la carpeta : ";
			cin >> nombre;
			cout << "Ingrese carpeta donde se guardara la carpeta: ";
			cin >> guardar1;
			F.CrearCarpeta(nombre1, guardar1);

			break;

		case 3:
			cout << "ingrese nombre de la carpeta : ";
			cin >> nombre2;

			cout << "Tamaño: " << F.obtenerTamano(nombre);

			break;

		case 4:
			F.imprimir();
			break;

		case 5:
			cout << "SALIENDO DEL SISTEMA" << endl;
			break;

		default:
			break;
		}


	} while (OpcionPrincipal != 5);
}