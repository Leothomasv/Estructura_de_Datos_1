#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	Stack<double> doubleStack;
	const size_t doubleStackSize{ 5 };
	double doubleValue{ 1.1 };

	cout << "Pushing elements onto doubleStack" << endl;

	for (size_t i{ 0 }; i < doubleStackSize; ++i) {
		doubleStack.push(doubleValue);
		cout << doubleValue << ' ';
		doubleValue += 1.1;
	}

	cout << "\n\n Popping elements from doubleStack\n";

	while (!doubleStack.isEmpty()) {
		cout << doubleStack.top() << ' ';
		doubleStack.pop();

	}
}
