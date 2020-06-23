#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
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
