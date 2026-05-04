#ifndef ALGORITMI_H_INCLUDED
#define ALGORITMI_H_INCLUDED
#include "functii.h"
    //unctei ce sorteaza vectorul crescator
    //                           0   1   2  3  4
    //  i<n   j<n  a[i]>a[j]     12  31  4 -2  14  j  i
    //  0<5   1<5    12>31 nu                      2
    //        2<5    12>4  da    4   31  12        3
    //        3<5    4>-2  da    -2  31  12  4 14  4
    //        4<5    -2>14 nu                      5
    //        5<5 nu                                  1
    //  1<5   2<5    31>12 da    -2  12  31  4 14  3
    //        3<5    12>4  da    -2  4  31  12 14  4
    //        4<5    12>14 nu                      5
    //        5<5 nu                                  2
    //  2<5   3<5    31>12 da    -2  4  12  31 14  4
    //        4<5    12>14 nu                      5
    //        5<5 nu                                  3
    // 3<5    4<5   31>14  da    -2  4  12  14 31  5
    //        5<5 nu                                  4
    // 4<5    5<5 nu
    //
    void sortarePrinSelectie(int a[], int n){
        for(int i=0; i<n; i++)
        {
           for(int j=i+1;j<n;j++){
                 if(a[i]>a[j])
                {
                    int aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
           }
        }
    }
    //                                 0   1    2   3   4
    //  sortat   i<n-1   a[i]>a[i+1]   124  5   2  91   0      sortat         i   sortat==false
    //  true      0<4      124>5 da     5   124 2  91   0       false         1
    //            1<4      124>2 da     5   2  124 91   0       false         2
    //            2<4      124>91 da    5   2  91  124  0       false         3
    //            3<4      124>0  da    5   2  91  0   124      false         4
    //            4<4 nu                                                           da
    //  true      0<4      5>2  da      2   5  91  0  124       false         1
    //            1<4      5>91 nu                                            2
    //            2<4      91>0 da      2   5  0  91  124       false         3
    //            3<4      91>124 nu                                          4
    //            4<4                                                              da
    //  true      0<4      2>5    nu                                          1
    //            1<4      5>0    da    2    0 5  91  124       false         2
    //            2<4      5>91   nu                                          3
    //            3<4      91>124 nu                                          4
    //            4<4                                                              da
    //  true      0<4      2>0    da     0   2  5  91  124       false         1
    //            1<4      2>5    nu     0   2  5  91  124                    2
    //            3<4

    void sortarePinBubbleSort(int a[],int n){

     bool sortat=false;
     do{
       sortat=true;
       for(int i=0; i<n-1; i++)
        {
           if(a[i]>a[i+1])
           {
                    int aux=a[i];
                    a[i]=a[i+1];
                    a[i+1]=aux;
                    sortat=false;
           }
        }


    }while(sortat==false);
    }


#endif // ALGORITMI_H_INCLUDED
