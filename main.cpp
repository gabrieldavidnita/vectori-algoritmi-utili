#include <iostream>
#include "solutii.h"

int main()
{
    int v[100], n, k=2,t=3;
    citireVector(v,n);
    afisareVector(v,n);
    int poz=pozitieDeControl(v,n,k,t);
    cout<<poz<<endl;

}
