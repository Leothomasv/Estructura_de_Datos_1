#include<iostream>
#include <list>

using namespace std;

int main() {

	list<int> valores;

	valores.push_back(8);
	valores.push_back(3);
	valores.push_back(1);
	valores.push_back(5);


	cout << "Cantidad de elementos: " << valores.size();

	list <int> ::iterator it;

	for (it = valores.begin(); it != valores.end(); it++) {

		cout << "\nPosicion de memoria: " << &(*it);
	}

}