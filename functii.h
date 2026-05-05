#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

// citire vector
void citireVector(int v[], int &dim)
{
    ifstream read("data.txt");

    read >> dim;

    for (int i = 0; i < dim; i++)
    {
        read >> v[i];
    }
}
// afisare vector
void afisareVector(int v[], int dim)
{ cout << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sortareCrescPeInterval(int a[], int dim, int mi, int ms)
{

    bool sortate = false;
    do
    {
        sortate = true;
        for (int i = mi; i < dim - 1 && i <= ms; i++)
        {
            cout << "test" << endl;
            if (a[i] > a[i + 1])
            {
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                sortate = false;
            }
        }

    } while (sortate == false);
}
//                                 0 1 2 3 4 5     mi=1  ms=5
// i<dim-1&&i>=mi    a[i]<a[i+1]   12 5 9 8 3 2     sortat     i
// 5<4
void sortareDescrPeInterval(int a[], int dim, int mi, int ms)
{
    bool sortate = false;
    do
    {
        sortate = true;
        for (int i = mi; i < dim - 1 && i <= ms; i++)
        {
            if (a[i] < a[i + 1])
            {
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                sortate = false;
            }
        }

    } while (sortate == false);
}

void sortareTipMunte(int a[], int dim, int k)
{
    sortareCrescPeInterval(a, dim, 0, k);
    sortareDescrPeInterval(a, dim, k, dim);
}
void sortareTipVale(int a[], int dim, int k)
{
    sortareDescrPeInterval(a, dim, 0, k);
    sortareCrescPeInterval(a, dim, k, dim);
}

int nrDivElement(int numar)
{
    int ct = 0;
    for (int i = 2; i <= numar / 2; i++)
    {
        if (numar % i == 0)
        {
            ct++;
        }
    }
    return ct;
}

//functie ce construieste un vector frecventa pe numere
//10,10,20,20,14,12,20
// intiere:i=0, n=7;
// i<n       10 11 12 13 14 15 16 17 18 19 20    i
// 0<7 da    1  0  0   0  0  0  0  0  0  0  0    1
// 1<7 da    2  0  0   0  0  0  0  0  0  0  0    2
// 2<7 da    2  0  0   0  0  0  0  0  0  0  1    3
// 3<7 da    2  0  0   0  0  0  0  0  0  0  2    4
// 4<7 da    2  0  0   0  1  0  0  0  0  0  2    5
// 5<7 da    2  0  1   0  1  0  0  0  0  0  2    6
// 6<7 da    2  0  1   0  1  0  0  0  0  0  3    7
// 7<7 nu

void frecventaNumarVec(int v[], int n,int f[])
{
        for(int i=0; i<n;i++)
        {

            f[v[i]]++;

        }

}
// 11  11  13  11 20  14  20        10 11 12 13 14  15 16 17 18 19 20
// initiere: i=10, pozmaxf=10, n=7  0  3  0  1  1    0  0  0  0 0  2
// i<21 f[i]>f[pozMax] pozMax  i
//  da   0>0                   11
//  da   3>0             3     12
//  da   0>3                   13
//  da   1>3                   14
//  da   1>3                   15
//  da   0>3                   16
//  da   0>3                   17
//  da   0>3                   18
//  da   0>3                   19
//  da   0>3                   20
//  nu


int  numarulCuFrecventaMaxDinVector(int v[], int n)
{
     int f[100]{};
     frecventaNumarVec(v,n,f);

    int pozMaxF=0;
    for(int i=0; i<100; i++)
    {
        if(f[i]>f[pozMaxF])
        {
            pozMaxF=i;
        }
    }

    return pozMaxF;

}


int numarulCuFrecventaMinDinVector(int v[], int n)
// 11  11  13  11 20  14  20        10 11 12 13 14  15 16 17 18 19 20
// initiere: i=10, pozminf=10, n=7  0  3  0  1  1    0  0  0  0 0  2
// i<21 f[i]<f[pozMax] pozminf  i
// da    0<0                    1
// da    3<0            0
{
    int f[100]{};
    frecventaNumarVec(v,n,f);
    f[0]=10;
    int pozMinF=0;
    for(int i=0;i<100;i++)
    {
        if(f[i]<f[pozMinF]&&f[i]!=0)
        {
            pozMinF=i;
        }


    }
return pozMinF;

}


void frecventa(int n, int f[])
{
    while(n!=0)
    {
        int uc=n%10;
        f[uc]++;
        n=n/10;
    }
}











#endif // FUNCTII_H_INCLUDED
