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
	long long int previo2 = 0;
	long long int previo = 1;
	long long int suma = 0;
	for (int i = 0; i < n; ++i)
	{
		suma = previo+previo2;
		previo2 = previo;
		previo = suma;
	}
	return previo;
}

int main()
{
	for (int i = 0; i < 1000; ++i)
	{
		cout<<fibonnacci_iterativo(50)<<endl;
	}
	
}