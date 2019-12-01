#include "PlanEstudio.h"


int main() {

	int OpcionPrincipal = 0;


	do {
		cout << "<<<< MENU PRINCIPAL >>>>" << endl;
		cout << "1. Crear Plan de Estudio" << endl;
		cout << "2. Iniciar/Cerrar Inscripcion de clases" << endl;
		cout << "3. Informacion Academica" << endl;
		cout << "4. Salir del sistema" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>" << endl;

		cout << "Ingrese opcion deseada: ";
		cin >> OpcionPrincipal;

		switch (OpcionPrincipal)
		{
		case 1:
			//Plan de estudio
			break;

		case 2:
			//Inciar Clases
			break;

		case 3:
			//Informacion academica
			break;

		case 4:
			cout << "Saliendo del sistema..." << endl;
		default:
			break;
		}
	} while (OpcionPrincipal !=4);

}