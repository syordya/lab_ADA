//Alumno: SANTOS/APAZA, YORDY WILLIAMS
//Repositorio: https://github.com/syordya/lab_ADA

#include <bits/stdc++.h>

using namespace std;

void sumamaxima(vector<int>& valores, int n,vector<int>& respuesta){

    int sumamax=0;
    int e=0;
    int d=-1;
    int suma=0;
    int i=0;
    int f=-1;
    while(f+1<n)
    {
        f++;
        suma+=valores[f];
        if(suma<0)
        {
            suma=0;
            i=f+1;
        }
        else
        {
           if(suma>sumamax)
           {
                sumamax=suma;
                e=i;
                d=f;
            }
        }
    }

    respuesta.push_back(e);
    respuesta.push_back(d);
    respuesta.push_back(sumamax);
}


int seg_max_dv(vector<int> &valores, int start, int fin)
{
    if(start == fin)
    {
        return max(0,valores[start]);
    }
    int medio = (start+fin) / 2;
    int maxizq = seg_max_dv(valores, start, medio);
    int maxder = seg_max_dv(valores, medio+1, fin);
    int max2izq, suma;
    max2izq = suma = valores[medio];
    for(int i = medio - 1; i>=start; i--)
    {
        suma += valores[i];
        max2izq = max(max2izq,suma);
    }

    int max2der = suma = valores[medio+1];

    for(int i = medio + 2; i<fin;i++)
    {
        suma += valores[i];
        max2der = max(max2der, suma);
    }
    int maxcruz = max2izq + max2der;
    return max(max(maxizq,maxcruz),maxder);

}


int main()
{
    int rutas;
    cin>>rutas;
    for(int i = 0; i< rutas; i++)
    {
        int calles,costo;
        vector<int> valores;
        vector<int> respuesta;

        cin>>calles;
        for(int j = 0; j < calles-1; j++)
        {
            cin>>costo;
            valores.push_back(costo);
        }

        sumamaxima(valores,valores.size(), respuesta);
        if (respuesta[2] > 0)
        {
            cout << "La mejor parte de la ruta "<<i+1 << " es entre las calles "<<respuesta[0]+1 << " y "<<respuesta[1]+1<<endl;
        }
        else
        {
            cout << "La ruta " << i+1<< " no tiene calles interesantes\n";
        }
    }

}
