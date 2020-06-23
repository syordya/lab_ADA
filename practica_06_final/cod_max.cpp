#include <bits/stdc++.h>
using namespace std;


int promedio_max(const vector<int> &a, int rango)
{
    int contador = 0;
    int val_max = a[0];
    for(int i = 1; i< rango; i++)
    {
        if(a[i] > val_max)
        {
            val_max = a[i];
            contador++;
        }
    }
    return contador;

}

void agregar_valor(vector<int> &a,int carga)
{
    fstream texto("data.txt");
    int aux;
    for (int i = 0; i < carga; i++)
    {
        texto >> aux;
        a[i] = aux;
    }
    texto.close();
}


void set_data(int tamanho,float value, float extra)
{
  fstream helper;
  helper.open("output.txt");
  helper.seekg (0,helper.end);
  helper << tamanho << " , ";
  helper<<fixed<<setprecision(3)<<value;
  helper << " , ";
  helper<<fixed<<setprecision(3)<<extra<<endl;
  helper.close();
}


void random_ex()
{
    ofstream a;
    a.open("data.txt");
    long long cantidad = pow(2,20);
    int aux;
    for(long long i = 0; i< cantidad;i++)
    {
        aux = rand()%2000000+1;
        a << aux << endl;
    }
    a.close();
}


int main()
{
  srand(time(0));
  const int cantidad_total = 1<<20;
  int val = 1<<8;
  int cont;
  int div_vals = 200;

  vector<int> data(20,0);
  vector<int> valores(cantidad_total);
  for(int k = 0; k < div_vals; k++)
  {

      random_ex();
      cont = 0;
      for(int i= val; i <= cantidad_total; i = i<<1)
      {
        agregar_valor(valores,i);
        data[cont++] += promedio_max(valores,i);

      }
  }
  cont = 0;
  for(int i= val; i <= cantidad_total; i = i<<1)
  {
      set_data(i, float(data[cont++])/float(div_vals), float(1) + log(i));

  }


}