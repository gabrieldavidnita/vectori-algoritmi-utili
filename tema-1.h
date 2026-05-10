#ifndef TEMA-1_H_INCLUDED
#define TEMA-1_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;
//problema 1(c)
void citireVector1(int v[], int &dim)
{
    ifstream read("data.txt");

    read >> dim;

    for (int i = 0; i < dim; i++)
    {
        read >> v[i];
    }
}
void afisareVector1(int v[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void frecventaNumarVec1(int v[], int n,int f[])
{
        for(int i=0; i<n;i++)
        {
            f[v[i]]++;
        }

}

int celMaiMareNrDouaCifreLipsa(int v[], int n)
{
    int f[101]={0};
    frecventaNumarVec1(v,n,f);
    for(int i=99;i>=10;i--)
    {
        if(f[i]==0)
        {
           return i;
        }
    }
    return -1;
}

// problema 1 d)

void frecventaCifreNumar(int n,int f[])
{
    while (n!=0)
    {
        int uc=n%10;
        f[uc]++;
        n=n/10;
    }
}

void frecventaCifreVector(int v[], int n, int cif[])
{
    for(int i=0; i<=9;i++)
        cif[i]=0;

    for(int i=0; i<n;i++)
        frecventaCifreNumar(v[i],cif);
}

void afisareCifreCareNuApar(int v[], int n)
{
    int cif[10];
    int gasit=0;

    frecventaCifreVector(v,n,cif);

    for (int i=0;i<=9;i++)
    {
        if (cif[i]==0)
        {
            cout<<i <<" ";
            gasit=1;
        }
    }

    if (gasit==0)
        cout<<"Toate cifrele apar in elementele vectorului";
}



// problema 1 e)

int elementMinim(int v[], int n)
{
    int minim = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i] < minim)
            minim = v[i];
    }

    return minim;
}

int frecventaElementMinim(int v[], int n)
{
    int minim = elementMinim(v, n);
    int nr = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == minim)
            nr++;
    }

    return nr;
}



int cifraMaxima(int v[], int n)
{
    int cif[10];

    frecventaCifreVector(v, n, cif);

    for (int i = 9; i >= 0; i--)
    {
        if (cif[i] != 0)
            return i;
    }

    return -1;
}

int frecventaCifraMaxima(int v[], int n)
{
    int cif[10];

    frecventaCifreVector(v, n, cif);

    int cmax = cifraMaxima(v, n);

    return cif[cmax];
}


//problema 2aa
void frecventaCifreNumar1(int n, int f[])
{
     while (n!=0)
    {
        int uc=n%10;
        f[uc]++;
        n=n/10;
    }
}

void afisareFrecventaCifre(int f[])
{
    for (int i=0; i <=9; i++)
        cout<<"Cifra "<<i<<" apare de "<<f[i]<<"ori " <<endl;

}

//problema 2ab

void cifreMaiMultDeK(int f[], int k)
{
    int exista=0;


    for (int i=0; i<=9; i++)
    {
        if (f[i]>k)
        {
            cout<<i<<" ";
            exista=1;
        }
    }
    if (exista==0)
        cout<<"nu exista";
    cout<<endl;
}

//problema 2ac
void celMaiMicNumarCifreImpareLipsa(int f[])
{
    int exista = 0;
    for (int i =1;i<=9;i=i+2)
    {
        if (f[i]==0)
        {
            cout<<i;
            exista=1;
        }
    }
    if(exista==0)
        cout<<" nu exista ";
    cout<<endl;
}

//problema 2ad?


//problema 2ae
int numarMinimCifreDeAdaugat(int f[])
{
    int maxi=f[0];
    for(int i=1; i<=9;i++)
    {
        if(f[i]>maxi)
            maxi=f[i];
    }
    int tot=0;

    for(int i=0;i<=9;i++)
        tot=tot+(maxi-f[i]);
    return tot;
}

//problema 2af
void vectorCifrePrimeLipsa(int f[],int v[],int &dim)
{
    dim=0;
    if (f[2]==0)
    {
        v[dim]=2;
        dim++;
    }
    if (f[3]==0)
    {
        v[dim]=3;
        dim++;
    }
    if(f[5]==0)
    {
        v[dim]=5;
        dim++;
    }
    if (f[7]==0)
    {
        v[dim]=7;
        dim++;
    }
}


//problema 2ag
//?

#endif // TEMA-1_H_INCLUDED
