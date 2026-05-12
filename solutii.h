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
     frecventa(numar,f);
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
void solutie1cd()
{
    int v[100], n;
    citireVector(v,n);

    cout<<endl;
    stergereElemPozVec(v,n,1);
       afisareVector(v,n);
}
// 232 531 121 563 434 121 322   , n=7
//                                 0   1   2   3   4   5   6
//i<n  isPrimaEgalaCuUltima(v[i]) 232 531 121 563 434 121 322   i
//0<7             da              531 121 563 434 121 322       0
//0<6             nu                                            1
//1<6             da              531 563 434 121 322           1
//1<5             nu                                            2
//2<5             da              531 563 121 322               2
//2<4             da              531 563 322                   2
//2<3             nu                                            3
//3<3 nu
void solutiee5()
{
    int v[100], n;
    citireVector(v,n);
    for(int i=0;i<n;i++){
        if(isPrimaEgalaCuUltima(v[i])){
            stergereElemPozVec(v,n,i);
            i--;
        }
    }
    afisareVector(v,n);
}



// n=8  , 2 4 6 3 5 -4 -2 9     0  1  2  3 4   5  6   7  8
//i<n      v[i]<0   putere     -2  4 -6  3 5  -4  -2  9  0   i
//0<8 da     da      -8        -2 -8  4 -6 3   5  -4 -2  9   1
//1<8 da
void solutieInserare1a()
{
    int v[100], n;
    citireVector(v,n);
    for(int i=0; i<n; i++)
    {


        if(v[i]<0)
        {
             int putere=pow(v[i],3);

            inserareElemPozVec(v,n,i+1,putere);
            i++;
        }
    }

    afisareVector(v,n);
}
void solutieInserare2a()
{
    int v[100],n;
    citireVector(v,n);
    afisareVector(v,n);
    int poz=pozKElement(v,n,3);
    int rast=oglNumar(v[poz]);
    inserareElemPozVec(v,n,poz+1,rast);
   afisareVector(v,n);

}


#endif // SOLUTII_H_INCLUDED
