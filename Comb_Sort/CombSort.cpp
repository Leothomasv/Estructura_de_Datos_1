// C++ implementation of Comb Sort 
#include <iostream> 
using namespace std;

// encontrar el espacio entre elementos 
int getNextGap(int gap)
{
	// reducir el espacio
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
}

void combSort(int a[], int n)
{
	int gap = n;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		// encontrar el siguiente espacio
		gap = getNextGap(gap);
		swapped = false;

		// Comparar todos los elementos
		for (int i = 0; i < n - gap; i++)
		{
			if (a[i] > a[i + gap])
			{
				swap(a[i], a[i + gap]);
				swapped = true;
			}
		}
	}
}

int main()
{
	int a[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
	int n = sizeof(a) / sizeof(a[0]);

	combSort(a, n);

	printf("Arreglo Ordenado: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
