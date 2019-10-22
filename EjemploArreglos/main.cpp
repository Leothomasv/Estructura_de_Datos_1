
#include <iostream>
#include <array>

using namespace std;

int main() {

	array<int, 5> arreglo;

	cout << "*** Ingreso de Valores  ***\n";

	for (int i = 0; i < 5; i++) {
		
		cout << "Ingrese valor en posicion array[" << i << "]:";
		cin >> arreglo[i];
	}

	int i = 0;
	for (int valor : arreglo) { // for each

		cout << "array[" << i++ << "]: " << valor << endl;
	}
}