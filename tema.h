#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;


void citireVector(int v[], int& dim){
    ifstream read("data.txt");

    read>>dim;

    for(int i=0;i<dim;i++)
    {
        read>>v[i];
    }
}

void afisareVector(int v[], int dim)
    {
        cout<<endl;
        for(int i=0; i<dim; i++){
             cout<<v[i]<<" ";
        }
        cout<<endl;

    }

//problema 1
int nrDivizoriProprii(int n) {
    int ct=0;

    for (int d=2; d<=n/2;d++)
    {
        if (n%d==0)
            ct++;
    }

    return ct;
}

int pozitieControl(int v[], int n) {
    int nr=0, div;

    for (int i=1; i<=n; i++) {
        div=nrDivizoriProprii(v[i]);

        if (div>=3 && div<=5) {
            nr++;
            if (nr==4)
                return i;
        }
    }

    return 0;
}

void sortareCrescPeInterval1(int a[], int dim, int mi, int ms)
{
    bool sortate = false;
    do
    {
        sortate = true;
        for (int i = mi; i < dim - 1 && i <=ms; i++)
        {
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
void sortareDescrPeInterval1(int a[], int dim, int mi, int ms)
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

void sortareMunte(int v[], int n)
{
    int p;

    p= pozitieControl(v, n);

    if (p == 0)
        cout << "Nu exista al 4-lea element cerut.";
    else
    {
        sortareCrescPeInterval1(v, n + 1, 1, p);
        sortareDescrPeInterval1(v, n + 1, p + 1, n);
    }
}

//problema 2
//? cum se face in baza 2



//problema 3
int pozPrimulMinim(int v[], int n)
{
    int i,p=1;
    for (i=2; i<=n; i++)
    {
        if (v[i]<v[p])
            p=i;
    }

    return p;
}

int pozUltimulMaxim(int v[], int n)
{
    int p=1;

    for (int i=2;i<=n;i++)
    {
        if (v[i] >= v[p])
        {
            p=i;
        }
    }
    return p;
}
void sortareSpeciala(int v[], int n)
{
    int pmin, pmax, aux;

    pmin=pozPrimulMinim(v, n);
    pmax=pozUltimulMaxim(v, n);

    if (pmin>pmax)
    {
        aux=pmin;
        pmin=pmax;
        pmax=aux;
    }
     for (int i = pmin + 1; i < pmax - 1; i++)
    {
        for (int j = i + 1; j < pmax; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}


//problema 4
void sortarePrinSelectie(int a[], int n){
        for(int i=0; i<n; i++)
        {
           for(int j=i+1;j<n;j++){
                 if(a[i]<a[j])
                {
                    int aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
           }
        }
    }

void sortareJumatati(int v[],int n) {
    int mij;
    mij=n/2;
     sortareCrescPeInterval1(v, n+1,1,mij);
    sortareDescrPeInterval1(v, n+1, mij+1, n);

}

//problema 5
void separare(int v[],int n,int p[],int &np,int imp[],int &ni)
{
    np=0;
    ni=0;
    for (int i=1;i<=n; i++)
    {
        if (v[i]%2==0) {
            np++;
            p[np]=v[i];
        }else{
            ni++;
            imp[ni]=v[i];
        }
    }
}


//transformare in baza 2
// 124
//initiere: p=1; nr=1;
//  n!=0         uc          nr        p         n
//  da           0           0         10       62
//  da           0           0         100      31
//  da           1           100       1000     15
//  da           1           1100      10000    7
//  da           1           11100     100000    3
//  da           1           111100    1000000   1
//  da           1           1111100   10000000  0
int decToBin(int n)
{
    int p=1;
    int nr=0;
    while(n!=0)
    {
      int  uc=n%2;
        nr=nr+uc*p;
        p=p*10;
        n=n/2;
    }
    return nr;
}


int  frecventaCifraNumar(int n,int cifra)
{
    int f[10]{};
    while(n!=0)
    {
        int uc=n%10;
        f[uc]++;
        n=n/10;
    }
    return f[cifra];

}
//initiere: nr=0
//
int pozitieDeControl(int v[], int n, int k, int t)
{
    int nr=0;
    for(int i=0; i<=n;i++)
    {
       if(frecventaCifraNumar(v[i],1)==t)
        {
            nr++;
           if(nr==k)
           {
               return i;
           }
        }
    }

    return -1;

}



void sortareTipVale(int v[], int dim, int k)
    {

        sortareDescrPeInterval1(v, dim, 0, k);
        sortareCrescPeInterval1(v, dim,k ,dim );

    }






#endif // TEMA_H_INCLUDED
