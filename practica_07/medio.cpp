#include <bits/stdc++.h>
using namespace std;



int getPivot(vector<int> &A);



/*  
  La función partition_median realiza una división del vector principal(A) en otros dos
  vectores(L y R), esto basandose en el valor del pivot(A[pivot]).
*/
int partition_median(vector<int> A, int pivot, vector<int> &L, vector<int> &R)
{

    for (int i = 0; i < A.size(); ++i)
    {
        // El valor del pivot no ire en ninguna de los otros 2 vectores.
        if(i == pivot) continue;

        // Si el valor es menor o igual al pivot, se almacenará en el vector L. 
        if(A[i] <= A[pivot])
        {
            L.push_back(A[i]);
        }
        // En caso de ser mayor ira en el vector R.
        else
        {
            R.push_back(A[i]);
        }
    }
    // Se devolvera el valor del elemento en la posición del pivot, el vector L, y el vector R.
    return A[pivot];
}



/*
  Esta función nos ayuda a obtener el n-esimo valor(k) más pequeño de un vector(A) considernado que este 
  desordenado en un tiempo lineal.
*/
int select_n_minimo(vector<int> &A, int k)
{

    // Con esa longitud del array principal A es necesario realizar un ordenamiento.
    // Y solo se devuelve el n-esimo valor consultado 
    if(A.size() <= 50)
    {
      sort(A.begin(), A.end());
      return A[k-1];
    }

    // Si el array es muy grande, se debe obtener un pivot.
    int p = getPivot(A);

    // Realizar una división del array en otros 2, basandonos en el pivot seleccionado.
    vector<int> L;
    vector<int> R;
    int pivotVal = partition_median(A,p, L, R);

    // En caso de que el tamaño de L, sea igual al n-esimo valor buscado - 1, devolvemos el valor del pivote
    if (L.size() == k-1)
    {
      return pivotVal;
    }
    // En caso de que el tamaño de L sea mayor al e-nesimo valor -1 , realizamos un busqueda solo por el array L
    else if (L.size() > k-1)
    {
      return select_n_minimo(L,k);
    }
    // En caso de que el tamaño de L sea menor al e-nesimo valor -1, se realiza la busqueda por el array R, 
    // pero reducimos el valor de consulta a n-esimo valor  - tamaño de L - 1, ya que el n-esimo valor
    // no esta en los elementos del vector L.
    else
    {
      return select_n_minimo(R, k - L.size() - 1);
    }
}


/*
  Esta función nos ayuda a seleccionar un pivote ideal utilizando el algoritmo de las medianas
*/
int getPivot(vector<int> &A)
{
    // Este vector de vectores(m), guardara los elementos del vector principal A.
    vector<vector<int>> m;
    int actual = 0;
    // En este bucle se dividira los elementos del vector A  en grupos de 5, y los almacenara en m
    while(actual < A.size())
    {
      int extra = A.size() > 5 + actual? 5 + actual : A.size(); 
      m.push_back(vector<int>(A.begin() + actual, A.begin() + extra));
      actual += extra;
    }

    // El vector p,  almacenará las medianas de cada vector en m
    vector <int> p;

    /* 
      Como son vectores con 5 elementos como máximo, solo se los ordenará y se almacenará el elemento central 
      del vector en el vector p.
    */
    for (int i = 0; i < m.size(); ++i)
    {
      vector<int> f(m[i].begin(), m[i].end());
      sort(f.begin(), f.end());
      p.push_back(f[f.size() / 2]);
    }

    // ahora se buscará el elemento central del array desordenado, utilizando la función propia select_n_minimo 
    int value = select_n_minimo(p,m.size()/2);

    /*
     Se realizará una busqueda en todo el vector principal(A) para obtener el indice del elemento central 
     obtenido previamente y almacenado en la variable value.
    */
    for (int i = 0; i < A.size(); ++i)
    {
        if(A[i] == value) return i;
    }

}




int main()
{
  
  int values;
  while(cin>>values)
  {
    vector<int> pruebas;
    int data;
    for (int i = 0; i < values; ++i)
    {
      cin>>data;
      pruebas.push_back(data);
    }
    cout << select_n_minimo(pruebas, int(float(pruebas.size())/2.0 + 0.5))<<endl;
  }

}
