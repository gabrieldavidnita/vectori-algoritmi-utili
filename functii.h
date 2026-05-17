#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <iostream>
#include <math.h>
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

//problema 1;
void stergereElemPozVec(int v[], int&dim, int poz)
{
    for(int i=poz; i<dim ;i++)
    {
        v[i]=v[i+1];
    }
    dim--;
}

bool isNumarPrim(int n)
{
    int ok=1;

    if(n<2){
        ok=0;
    }
    for(int d=2; d<=n/2; d++)
    {
        if(n%d==0){
            ok=0;
        }
    }

    return ok;
}

// 45 23 34 45 34  dim=5, poz=0; ct=0
// i   i<dim   ct!=3   numarprim   ct     ct==3   poz   i
// 0   0<5     0!=3 da   nu                             1
// 1   1<5     0!=3 da   da        1                    2
// 2   2<5     1!=3 da   da        2                    3
// 3   3<5     2!=3 da   nu                             4
// 4   4<5     2!=3 da   da        3                    5
// 5   5<5 nu                              da       5




int pozVecElemPrim(int v[], int dim)
{
    int poz=0;
    int ct=0;
    for(int i=0; i<dim&ct!=3; i++)
    {
        if(isNumarPrim(v[i]))
        {
            ct++;
        }
        if(ct==3 )
        {
            poz=i;
        }
    }
    return poz;
}

bool isPrimaEgalaCuUltima(int n)
{
    int ok=0;
    int uc=n%10;
    while(n>=10)
    {
        n=n/10;
    }
    int prima=n;
    if(prima==uc)
    {
     ok=1;
    }else{

    ok=0;
    }
    return ok;
}


//problema 1 , 12.05.2026

void inserareElemPozVec(int v[], int&dim , int poz, int nr)
{
    for(int i=dim-1; i>=poz; i--)
    {
        v[i+1]=v[i];

    }
    dim++;
    v[poz]=nr;

}
//n=34567   uc=7  ok=1
// n!=0    n      penc  uc  uc>penc  ok  n
// da    3456      7     6  6>7 nu    -  345
// da              6     5  5>7 nu    -  34
// da              5     4  4>5 nu    -  3
// da              4     3  3>5 nu    -  0
// nu
//ok=1
//1234
//uc 4, n=123
// n!=0    pc   uc   uc-1!=pc  ok   n
// da      4    3
bool isNumarCuCifreConsecutive(int n)
{  int ok=1;
   int uc=n%10;
   n=n/10;
    while(n!=0)
    {

        int pc=uc;
        uc=n%10;
        if(pc-1!=uc){
            ok=0;
        }
        n=n/10;
    }
    return ok;
}
// 8
//123 434 456 403 123 145 567 993
// i<dim  isNumarCuCifreConsecutive(v[i])  ct  ct==k  poz   i
// 0<8              da                     1     nu    -    1
// 1<8              nu                     -     nu    -    2
// 2<8              da                     2     nu    -    3
// 3<8              nu                     -     nu    -    4
// 4<8              da                     3     da    4    5
// 5<8              nu                     -     da    5

int pozKElement(int v[], int dim, int k)
{
    int ct=0;
    int poz=0;
    for(int i=0; i<dim&&ct!=k; i++)
    {

        if (isNumarCuCifreConsecutive(v[i]))
        {
           ct++;
        }
        if(ct==k)
        {
            poz=i;
        }
    }
    return poz;
}

int oglNumar(int n)
{
    int ogl=0;
    while(n!=0)
    {
      int uc=n%10;
      ogl=ogl*10+uc;
      n=n/10;
    }
    return ogl;
}


bool isnumerePalindroame(int a ,int b)
{
    int ok=1;
   if(oglNumar(a)!=b)
   {
       ok=0;
   }
   return ok;
}
//123 de 456 123000 +456 =>123456
int alipireNumere(int a,int b)
{
    int copie=b;

    while(copie!=0)
    {
        a=a*10;
        copie=copie/10;
    }
    return a+b;
}


#endif // FUNCTII_H_INCLUDED
