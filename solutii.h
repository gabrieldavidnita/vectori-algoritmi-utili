#ifndef SOLUTII_H_INCLUDED
#define SOLUTII_H_INCLUDED
#include "tema.h"


void solutie1()
{
    int v[101], n;
    citireVector(v,n);
    sortareMunte(v, n);
    afisareVector(v, n);
}
void solutie3()
{
    int v[201], n;
    citireVector(v, n);
     afisareVector(v, n);
     cout<<endl;
    sortareSpeciala(v, n);

}
void solutie4()
{
    int v[1001], n;
    citireVector(v, n);
    afisareVector(v, n);
    sortareJumatati(v, n);
}
void solutie5()
{
    int v[1001], p[1001], imp[1001];
    int n, np, ni;
    citireVector(v, n);
    separare(v, n, p, np, imp, ni);
    sortareCrescPeInterval1(p, np + 1, 1, np);
    sortareDescrPeInterval1(imp, ni + 1, 1, ni);
    afisareVector(v, n);
}

#endif // SOLUTII_H_INCLUDED
