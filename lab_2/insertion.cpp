//Yordy Williams Santos Apaza
//Repositorio en GitHub: https://github.com/syordya/lab_ADA
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
using namespace std;
#define T 10000
void insertionSort(int arr[], int n)
{
    int i, llave, j;
    for (i = 1; i < n; i++) {
        llave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > llave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = llave;
    }
}
void showArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    cout<< " "<< arr[i];
    cout<<"\n";
}
int main()
{
	unsigned t0, t1;
	int n;
	srand(time(NULL));
    t0=clock();
	int a[T];
	int aux=T;
//CRECIENTE
	for (int i = 0; i <T; i++) {
		n=i+1;
		a[i] = n;
	}

//DECRECIENTE
//	for (int i = 0; i <T; i++) {
//		n=aux-i;
//		a[i] = n;
//	}
    insertionSort(a, T);
    showArray(a, T);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Runtime: " << time << endl;
    return 0;
}
