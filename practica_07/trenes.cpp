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
            if(j-i) contador_global+=(j-i);
        }
    }
    int distancia = high - (i+1);
    contador_global += (distancia*2 - 1 >= 0? distancia*2 - 1:0 );
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


int main()
{
    int casos;
    cin>>casos;
    for (int k = 0; k < casos; ++k)
    {
        int data, L;
        cin>>L;
        vector<int> values;
        for (int i = 0; i < L; ++i)
        {
            cin>>data;
            values.push_back(data);
        }
        contador_global = 0;
        quickSort(values, 0, values.size()-1);

        cout << "La mejor cantidad de swaps de trenes es "<< contador_global<<" swaps"<<endl;
    }
    
    return 0;
}