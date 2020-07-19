#include<bits/stdc++.h>
using namespace std;

// Matrices a utilizarse
int dp[130][130];
int matrix[130][130];


int main()
{
	int n;
	cin>>n;
	// Lectura de matriz
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>> matrix[i][j];
		}
	}
	// Todos los valores estaran en cero en la matriz DP
	memset(dp,0,sizeof dp);

	// se iniciará desde la posición 1,1 en la matriz
	// Gestion de la matriz dp o matriz acumuladora
	dp[1][1]=matrix[1][1]; // Inicializador
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// Sumatoria hasta la posición i,j
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];

		}
	}

	int res=INT_MIN;
	int z, p, q, r;
	// Primeros dos for para establecer la posición Superior-Izquierda
	for(int x1=0;x1<n;x1++)
	{
		for(int y1=0;y1<n;y1++)
		{
			// estos dos fors son para la busqueda en diferentes formas en la matriz (2x3, 3x2, 4x1, etc)
			// Tambien son para definir la posición Inferior derecha de la matriz a evaluar

			for(int x2=x1+1;x2<=n;x2++)
			{
				for(int y2=y1+1;y2<=n;y2++)
				{
					// verificación de la sumatoria maxima obtenida
					z = dp[x2][y2];
					p = dp[x1][y2];
					q = dp[x2][y1];
					r = dp[x1][y1];
					res=max(res,z-p-q+r);
				}
			}
		}
	}
	
	cout << res << endl;
}

