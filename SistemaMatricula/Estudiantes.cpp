#include "Estudiantes.h"
#include "PlanEstudio.h"


PlanEstudio plan;

void Estudiantes::agregarEstudiante()
{
	ofstream filePensum("Estudiante.dat", ios::binary);

	Estudiantes estu;
		cout << "<>><><><><><><><>><><><><><>><><><>" << endl;
		cout << "Ingrese nombre de estudiante:";
		cin >> estu.NombreEstudiante;
		cout << "Ingrese numero de cuenta:";
		cin >> estu.NumeroCuenta;
		cout << "Ingrese nombre del Plan de estudio:";
		cin >> estu.codigoPlanEstudio;
		cout << "<>><><><><><><><>><><><><><>><><><>" << endl;
		//binario
		filePensum.write(reinterpret_cast<const char*>(&estu), sizeof(Estudiantes));
	filePensum.close();
}

void Estudiantes::leerEstudiante()
{
	ifstream filePensum("Estudiante.dat", ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);
	Estudiantes lectura;
	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(Estudiantes));
	while (!filePensum.eof()) {
		cout << "Nombre: " << lectura.NombreEstudiante << endl;
		cout << "Numero de cuenta: " << lectura.NumeroCuenta << endl;
		cout << "Nombre del plan: " << lectura.codigoPlanEstudio << endl;
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(Estudiantes));
	}
	filePensum.close();
}
void Estudiantes::registrarNotas() {
	ifstream filePensum("HistorialAcademico.dat", ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);

	MateriMatriculada lectura;
	int Uv = 0;
	float resultado = 0;
	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	while (!filePensum.eof()) {
		if (lectura.nota==0)
		{
			PlanEstudio p;
			int nota = 0;
			cout << "Clase: " << lectura.codigo << " " << lectura.nombre<<" <<Ingrese Nota>>: ";
			cin >> nota;
			p.ModificarNota(lectura.codigo, nota);
		}
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(MateriMatriculada));
	}
	filePensum.close();


}
void Estudiantes::matricular(string codigo,string nombre,int uv,int nota)
{
	PlanEstudio c;
	MateriMatriculada m;
	ofstream filePensum("HistorialAcademico.dat",  ios::out | ios::binary | ios::app);

	strcpy(m.codigo, codigo.c_str());
	strcpy(m.nombre, nombre.c_str());
	m.nota = 0;
	m.uv = uv;
	filePensum.write(reinterpret_cast<const char*>(&m), sizeof(MateriMatriculada));
	filePensum.close();
}



string Estudiantes::obtenerCarrera() {
	ifstream filePensum("Estudiante.dat", ios::in | ios::binary);
	filePensum.seekg(0, ios::beg);
	Estudiantes lectura;
	filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(Estudiantes));
	while (!filePensum.eof()) {
		return lectura.codigoPlanEstudio;
		filePensum.read(reinterpret_cast<char*>(&lectura), sizeof(Estudiantes));
	}
	filePensum.close();
}


