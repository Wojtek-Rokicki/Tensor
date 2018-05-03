#include <iostream>
#include <typeinfo>
#include <complex>
#include "tests.h"
#include "tensor.h"

using namespace std;

void tests(){
    if(test1()) cout<<"Test 1: PASS"<<endl;
    else cout<<"Test 1: FAIL"<<endl;

    /*if(test2()) cout<<"Test 2: PASS"<<endl;
    else cout<<"Test 2: FAIL"<<endl;

    if(test3()) cout<<"Test 3: PASS"<<endl;
    else cout<<"Test 3: FAIL"<<endl;

    if(test4()) cout<<"Test 4: PASS"<<endl;
    else cout<<"Test 4: FAIL"<<endl;

    if(test5()) cout<<"Test 5: PASS"<<endl;
    else cout<<"Test 5: FAIL"<<endl;*/
}

bool test1()
{
    /* TEST LICZB CALKOWITYCH */

    Tensor<int> A(2,2,2);  /* tensor testowy */
    Tensor<int> B(2,2,2);  /* tensor testowy */
    Tensor<int> C(2,2,2);  /* pomocniczy tensor testowy */
    
    Tensor<int> Wynik_dod(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<int> Wynik_mn(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<int> Wynik_ode(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    int  elem1_1=3,  elem2_1=4,  elem3_1=3,  elem4_1=0;
    int elem5_1=-1, elem6_1=4, elem7_1=2, elem8_1=3;
    /* elementy drugiego tensora */
    int elem1_2=1, elem2_2=4, elem3_2=3, elem4_2=6;
    int elem5_2=2, elem6_2=10, elem7_2=1, elem8_2=9;
    /* WPISYWANIE WARTOSCI TENSORA A */
    A.change(1,1,1, elem1_1);
    A.change(1,1,2, elem2_1);
    A.change(1,2,1, elem3_1);
    A.change(1,2,2, elem4_1);
    A.change(2,1,1, elem5_1);
    A.change(2,1,2, elem6_1);
    A.change(2,2,1, elem7_1);
    A.change(2,2,2, elem8_1);
    
    cout<<A<<endl;

    /* WPISYWANIE WARTOSCI TENSORA B */
    B.change(1,1,1, elem1_2);
    B.change(1,1,2, elem2_2);
    B.change(1,2,1, elem3_2);
    B.change(1,2,2, elem4_2);
    B.change(2,1,1, elem5_2);
    B.change(2,1,2, elem6_2);
    B.change(2,2,1, elem7_2);
    B.change(2,2,2, elem8_2);

    cout<<B<<endl;

    /* WPISYWANIE WARTOSCI TENSORA BEDACEGO WYNIKIEM DODAWANIA */
    Wynik_dod.change(1,1,1, elem1_1+elem1_2);
    Wynik_dod.change(1,1,2, elem2_1+elem2_2);
    Wynik_dod.change(1,2,1, elem3_1+elem3_2);
    Wynik_dod.change(1,2,2, elem4_1+elem4_2);
    Wynik_dod.change(2,1,1, elem5_1+elem5_2);
    Wynik_dod.change(2,1,2, elem6_1+elem6_2);
    Wynik_dod.change(2,2,1, elem7_1+elem7_2);
    Wynik_dod.change(2,2,2, elem8_1+elem8_2);
    /* WPISYWANIE WARTOSCI TENSORA BEDACEGO WYNIKIEM ODEJMOWANIA */
    Wynik_ode.change(1,1,1, elem1_1-elem1_2);
    Wynik_ode.change(1,1,2, elem2_1-elem2_2);
    Wynik_ode.change(1,2,1, elem3_1-elem3_2);
    Wynik_ode.change(1,2,2, elem4_1-elem4_2);
    Wynik_ode.change(2,1,1, elem5_1-elem5_2);
    Wynik_ode.change(2,1,2, elem6_1-elem6_2);
    Wynik_ode.change(2,2,1, elem7_1-elem7_2);
    Wynik_ode.change(2,2,2, elem8_1-elem8_2);
    /* WPISYWANIE WARTOSCI TENSORA BEDACEGO WYNIKIEM MNOZENIA */
    Wynik_mn.change(1,1,1, elem1_1*elem1_2);
    Wynik_mn.change(1,1,2, elem2_1*elem2_2);
    Wynik_mn.change(1,2,1, elem3_1*elem3_2);
    Wynik_mn.change(1,2,2, elem4_1*elem4_2);
    Wynik_mn.change(2,1,1, elem5_1*elem5_2);
    Wynik_mn.change(2,1,2, elem6_1*elem6_2);
    Wynik_mn.change(2,2,1, elem7_1*elem7_2);
    Wynik_mn.change(2,2,2, elem8_1*elem8_2);

    if(A.read(1,2,2)!=elem4_1)
       { return false; }
    if(B.read(2,1,1)!=elem5_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A+=B;
    if(A!=Wynik_dod)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

