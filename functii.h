#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <iostream>
#include<fstream>
using namespace std;

//citire vector
void citireVector(int v[], int& dim){
    ifstream read("data.txt");

    read>>dim;

    for(int i=0;i<dim;i++)
    {
        read>>v[i];
    }
}
//afisare vector
    void afisareVector(int v[], int dim)
    {
        cout<<endl;
        for(int i=0; i<dim; i++){
             cout<<v[i]<<" ";
        }
        cout<<endl;

    }

 void sortareCrescPeInterval(int a[], int dim, int mi,int ms)
 {

    bool sortate=false;
      do{
        sortate=true;
        for(int i=mi; i<dim-1 && i<=ms ; i++)
        {
            cout<<"test"<<endl;
            if(a[i]>a[i+1])
           {
                    int aux=a[i];
                    a[i]=a[i+1];
                    a[i+1]=aux;
                    sortate=false;
           }
        }

      }while(sortate==false);
 }
 //                                 0 1 2 3 4 5     mi=1  ms=5
 // i<dim-1&&i>=mi    a[i]<a[i+1]   12 5 9 8 3 2     sortat     i
 // 5<4
 void sortareDescrPeInterval(int a[], int dim , int mi, int ms)
 {
     bool sortate=false;
      do{
        sortate=true;
        for(int i=mi; i<dim-1 && i<=ms ; i++)
        {
            if(a[i]<a[i+1])
           {
                    int aux=a[i];
                    a[i]=a[i+1];
                    a[i+1]=aux;
                    sortate=false;
           }
        }

      }while(sortate==false);
 }

 void sortareTipMunte(int a[], int dim , int k)
 {
     sortareCrescPeInterval(a,dim,0,k);
     sortareDescrPeInterval(a,dim,k,dim);
 }
 void sortareTipVale(int a[], int dim , int k)
 {
     sortareDescrPeInterval(a,dim, 0, k);
     sortareCrescPeInterval(a,dim, k ,dim);
 }

 int nrDivElement(int numar)
 {
     int ct=0;
     for(int i=2;i<=numar/2;i++){
        if(numar%i==0)
        {
            ct++;
        }
     }
     return ct;
 }

 int pozElementCuNrDiv();
#endif // FUNCTII_H_INCLUDED
