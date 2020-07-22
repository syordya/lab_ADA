#include<bits/stdc++.h>
using namespace std;




int fibonnacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fibonnacci(n-1)+ fibonnacci(n-2));
}



long long int fibonnacci_iterativo(int n)
{
	if(n==0) return 0;
	long long int previo2 = 0;
	long long int previo = 1;
	long long int suma = 0;
	for (int i = 1; i < n; ++i)
	{
		suma = previo+previo2;
		previo2 = previo;
		previo = suma;
	}
	return previo;
}

//Diapos


long long int fibo_tabla(const int n)
{
	long long int arreglo_fibonnacci[n];
	arreglo_fibonnacci[0] = 0;
	arreglo_fibonnacci[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		arreglo_fibonnacci[i] = arreglo_fibonnacci[i-1] + arreglo_fibonnacci[i-2];
	}
	return arreglo_fibonnacci[n];
}


long long int fibo_iter(int n)
{
	if(n==0) return 0;
	long long int anterior = 0;
	long long int actual = 1;
	long long int proximo = 0;
	for (int i = 2; i < n; ++i)
	{
		proximo = actual+anterior;
		anterior = actual;
		actual = proximo;
	}
	return actual;
}



int main()
{
	time(0);
	for (int i = 0; i < 10000; ++i)
	{
		//cout << fibonnacci(200)<<endl;
		long long int a = fibo_tabla(rand() % 500);
		//long long int b = fibo_iter(rand() % 500);
		cout << "---------------------"<<endl;
	}
	
}