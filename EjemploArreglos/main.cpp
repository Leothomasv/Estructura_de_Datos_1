
#include <iostream>
#include <array>
#include <vector>

using namespace std;

void insertarArray(array<int, 5> &);
void imprimirArray(const array <int, 5> &);

void insertarVector(vector<int> &);
void imprimirVector(const vector<int>&);

int main() {
	
	array<int, 5> arreglo;
	vector<int> arreglo2(5);

	cout << "*** Ingreso de Valores  ***\n";
	
	//esto es para saber la posicion en memoria
	/*for (int i = 0; i < 5; i++) {
		cout << "Posicion de memoria: array[" << i << "]: " << &arreglo[i] << endl;
	}*/


	//insertarArray(arreglo);
	//imprimirArray(arreglo);

	insertarVector(arreglo2);
	imprimirVector(arreglo2);

	
}

void insertarArray( array<int, 5> &arreglo) {

	/*for (int valor : arreglo) {

	}*/


	int item = 0;
	for (int i = 0; i < 5; i++) {

		cout << "Ingrese valor en posicion array[" << i << "]:";
		cin >> arreglo[i];
	
	}
}

void imprimirArray(const array<int, 5>& arreglo) {

	int i = 0;
	for (int valor : arreglo) { // for each

		cout << "array[" << i++ << "]: " << valor << endl;
	}

}

void insertarVector(vector <int> &arreglo) {

	for (int& valor : arreglo) { //puso referencia en el valor porque ahi quiere ingresar en posicion de memoria el valor
		cout << "Ingrese elemento a vector: ";
		cin >> valor;
	}

}

void imprimirVector(const vector<int> &arreglo) {

	for (int valor : arreglo) {

		cout << "Valor en arreglo: " << valor << endl;
	}
}