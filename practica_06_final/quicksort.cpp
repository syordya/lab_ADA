#include <bits/stdc++.h>
using namespace std;
int contador_global = 0;
void swap(int &a,int &b)
{
    int temp = b;
    b = a;
    a = temp;
}



int partition (vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
            contador_global++;
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}


void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {

        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}



void agregar_valor(vector<int> &a,int carga)
{
    fstream texto("data_quick.txt");
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
  helper.open("output_quick.txt");
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
    a.open("data_quick.txt");
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
  vector<int> valores(cantidad_total + 1);
  for(int k = 0; k < div_vals; k++)
  {
      cout << k << endl;
      random_ex();
      cont = 0;
      for(int i= val; i <= cantidad_total; i = i<<1)
      {
        agregar_valor(valores,i);
        quickSort(valores, 0, i);
        data[cont++] += contador_global;
        contador_global = 0;

      }
  }
  cont = 0;
  for(int i= val; i <= cantidad_total; i = i<<1)
  {
      set_data(i, float(data[cont++])/float(div_vals), float(i) * log(i));

  }

}
