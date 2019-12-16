#include "PlanEstudio.h"
#include "Estudiantes.h"

void menu() {
	int OpcionPrincipal = 0;
	int infoOpc = 0;
	string NombrePensum;

	PlanEstudio plan;
	Estudiantes estudiante;
	do {
		cout << "\n";
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
			cout << "-------------------------------------------------------" << endl;
			cout << "Ingrese nombre del pensum: ";
			cin >> NombrePensum;
			plan.crearPensum(NombrePensum);
			break;

		case 2:
			cout << "\n";
			cout << "<<Pensums disponibles>>" << endl;
			plan.leerVector();
			cout << "\n";
			estudiante.agregarEstudiante();
			break;

		case 3:
			plan.leerPensum();
			cout << "\n";
			cout << "<<Clases disponibles>>" << endl;
			plan.obtenerClasesDisponibles();
			estudiante.registrarNotas();
			break;

		case 4:
			cout << "\n";
			plan.obtenerHistorialAcademico();
			break;

		case 5:
			cout << "Saliendo del sistema..." << endl;
		default:
			break;
		}
	} while (OpcionPrincipal != 5);




}

int main() {
	PlanEstudio p;
	//rClasesDisponibles();

	menu();
}



	