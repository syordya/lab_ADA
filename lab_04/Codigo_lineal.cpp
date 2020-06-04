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

    while(f<n){
        f++;
        suma=suma+valores[f];
        if(suma<0){
            suma=0;
            i=f+1;
        }else{
            if(suma>sumamax){
                    sumamax=suma;
                    e=i;
                    d=f;
            }
        }
    }
    respuesta[0]=e;
    respuesta[1]=d;
    respuesta[2]=sumamax;
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
