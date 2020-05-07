//Yordy Williams Santos Apaza
//Repositorio en GitHub: https://github.com/syordya/lab_ADA
#include<iostream>
#include<vector>
#include <ctime>
using namespace std;
#define T 10000
int main() {
	unsigned t0, t1;
	t0 = clock();
	srand(time(NULL));
	int a[T];
	int t;
	int n ;
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
for (int j = T - 1; j > 0; j--) {
    for (int i = 0; i < j; i++) {
        if (a[i] > a[i + 1]) {
            t = a[i + 1];
            a[i + 1] = a[i];
            a[i] = t;
        }
    }
}
for (int i = 0; i < T; i++) {
    cout << " " << a[i];
}
    cout<<"\n";
	t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Runtime: " << time << endl;
}
