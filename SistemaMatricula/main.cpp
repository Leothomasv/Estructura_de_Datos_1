#include "PlanEstudio.h"


int main() {

	int OpcionPrincipal = 0;
	string NombrePensum;
	

	PlanEstudio nuevo;
	do {
		cout << "<<<< MENU PRINCIPAL >>>>" << endl;
		cout << "1. Crear Pensum" << endl;
		cout << "2. Matricularse" << endl;
		cout << "3. Iniciar/Cerrar Inscripcion de clases" << endl;
		cout << "4. Informacion Academica" << endl;
		cout << "5. Salir del sistema" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>" << endl;

		cout << "Ingrese opcion deseada: ";
		cin >> OpcionPrincipal;

		switch (OpcionPrincipal)
		{
		case 1:
			//Crear Pensum
			cout << "Ingrese nombre del pensum: ";
			cin >> NombrePensum;
			nuevo.crearPensum(NombrePensum);
			break;

		case 2:

			break;

		case 3:

			break;
		case 4:

			break;

		case 5:
			cout << "Saliendo del sistema..." << endl;
		default:
			break;
		}
	} while (OpcionPrincipal !=5);

}