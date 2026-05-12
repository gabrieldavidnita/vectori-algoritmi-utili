#ifndef SOLUTII-1_H_INCLUDED
#define SOLUTII-1_H_INCLUDED
#include"tema-1.h"

void solutie1ca()
{
    int v[2000], n;
    citireVector1(v,n);
    afisareVector1(v,n);
    cout<<endl;
    int nr=celMaiMareNrDouaCifreLipsa(v,n);
    if (nr==-1)
        cout<<"Toate numerele de 2 cifre apar in vector";
    else
        cout<<"Cel mai mare numar de 2 cifre care nu apare in vector este "<< nr;
}

void solutie1da()
{
    int v[2000], n;
    citireVector1(v, n);
    afisareVector1(v, n);
    cout<<endl;
    cout << "Cifrele care nu apar in elementele vectorului sunt: ";
    afisareCifreCareNuApar(v, n);
}
void solutie1ea()
{
    int v[2000], n;

    citireVector(v, n);
    afisareVector(v, n);

    cout << endl;

    cout << "Elementul minim este "<< elementMinim(v,n)<<endl;
    cout << "Frecventa elementului minim este " << frecventaElementMinim(v,n)<<endl;

    cout << "Cifra maxima este "<<cifraMaxima(v,n)<<endl;
    cout << "Frecventa cifrei maxime este " <<frecventaCifraMaxima(v,n);
}
void solutie2aa()
{
    int n;
    int f[10]{};

    cout<<"n= ";
    cin>>n;
    frecventaCifreNumar1(n, f);
    cout<<"Frecventa cifrelor este:"<<endl;
    afisareFrecventaCifre(f);
}
void solutie2ab()
{
    int n,k;
    int f[10]{};
    cout<<" n= ";
    cin>>n;
    cout<<" k= ";
    cin>>k;
    frecventaCifreNumar1(n, f);
    cifreMaiMultDeK(f,k);
}
void solutie2ac()
{
    int n;
    int f[10]{};
    cout<<" n= ";
    cin>>n;
    frecventaCifreNumar1(n,f);
    celMaiMicNumarCifreImpareLipsa(f);
}
void solutie2ae()
{
    int n;
    int f[10]{};
    cout << "n= ";
    cin >> n;
    frecventaCifreNumar(n, f);
    cout<<" Numarul minim de cifre care trebuie adaugate este ";
    cout<<numarMinimCifreDeAdaugat(f)<<endl;
}
void solutie2af()
{
    int n;
    int f[10]{};
    int v[4],dim;
    cout<<"n= ";
    cin>>n;
    frecventaCifreNumar1(n,f);
    vectorCifrePrimeLipsa(f,v,dim);
    cout << "Vectorul cu cifre prime care nu apar este ";
    afisareVector1(v,dim);
}

void solutie2ag()
{
    int n;
    int f[10]{};
    cout<<" n= ";
    cin>>n;
    frecventaCifreNumar(n,f);
    int minim=aflareMinim(f);
    cout<<" Cel mai mic numar care se poate forma din cifrele numarului initial este "<<minim<<endl;
}




#endif // SOLUTII-1_H_INCLUDED
