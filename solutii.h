#ifndef SOLUTII_H_INCLUDED
#define SOLUTII_H_INCLUDED
#include "functii.h"

void solutie1a()
{
int v[100], n;
citireVector(v,n);
afisareVector(v,n);
cout<<endl;
cout<<"Numarul cu frecventa cea mai mare este" << numarulCuFrecventaMaxDinVector(v,n) <<endl;
cout<<"Numarul cu frecventa cea mai mica este" << numarulCuFrecventaMinDinVector(v,n) <<endl;
}

void solutie2a()
{
     int numar;
     cout<<"numar=";
     cin>>numar;
     int f[10]{};
     frecventaCifra(numar,f);
    for(int i=0; i<10; i++)
        if(f[i]>0)
    {
        cout<<i<<" frecventa "<<f[i]<<endl;
    }
}

void solutie3a()
{
   int v[100],  n ,  f[100]{};
   citireVector(v,n);
   afisareVector(v,n);
   cout<<endl;
   frecventaNumarVec(v,n,f);
   for(int i=0; i<100; i++)
   {
       if(f[i]>0)
       {
           cout<<i<<" frecventa "<<f[i]<<endl;
       }
   }
}



#endif // SOLUTII_H_INCLUDED
