#include <iostream>
#include <typeinfo>
#include <complex>
#include "tests.h"
#include "tensor.h"

using namespace std;

void tests(){
    if(test1()) cout<<"Test 1: PASS"<<endl;
    else cout<<"Test 1: FAIL"<<endl;

    if(test2()) cout<<"Test 2: PASS"<<endl;
    else cout<<"Test 2: FAIL"<<endl;
}

//Test tensora liczb calkowitych
bool test1()
{
    Tensor<int> A(2,2,2);  /* tensor testowy */
    Tensor<int> B(2,2,2);  /* tensor testowy */
    Tensor<int> C(2,2,2);  /* pomocniczy tensor testowy */
    
    Tensor<int> dodawanie(2,2,2);
    Tensor<int> odejmowanie(2,2,2);
    Tensor<int> mnozenie(2,2,2);

    A.change(1,1,1, 2);
    A.change(1,1,2, 4);
    A.change(1,2,1, 8);
    A.change(1,2,2, 0);
    A.change(2,1,1, 1);
    A.change(2,1,2, 4);
    A.change(2,2,1, 1);
    A.change(2,2,2, 3);
    
    cout<<A<<endl;

    B.change(1,1,1, 3);
    B.change(1,1,2, 3);
    B.change(1,2,1, 3);
    B.change(1,2,2, 3);
    B.change(2,1,1, 3);
    B.change(2,1,2, 3);
    B.change(2,2,1, 3);
    B.change(2,2,2, 3);

    cout<<B<<endl;

    dodawanie.change(1,1,1, 5);
    dodawanie.change(1,1,2, 7);
    dodawanie.change(1,2,1, 11);
    dodawanie.change(1,2,2, 3);
    dodawanie.change(2,1,1, 4);
    dodawanie.change(2,1,2, 7);
    dodawanie.change(2,2,1, 4);
    dodawanie.change(2,2,2, 6);

    odejmowanie.change(1,1,1, -1);
    odejmowanie.change(1,1,2, 1);
    odejmowanie.change(1,2,1, 5);
    odejmowanie.change(1,2,2, -3);
    odejmowanie.change(2,1,1, -2);
    odejmowanie.change(2,1,2, 1);
    odejmowanie.change(2,2,1, -2);
    odejmowanie.change(2,2,2, 0);

    mnozenie.change(1,1,1, 6);
    mnozenie.change(1,1,2, 12);
    mnozenie.change(1,2,1, 24);
    mnozenie.change(1,2,2, 0);
    mnozenie.change(2,1,1, 3);
    mnozenie.change(2,1,2, 12);
    mnozenie.change(2,2,1, 3);
    mnozenie.change(2,2,2, 9);

    if(A.read(1,2,2)!=0)
       { return false; }
    if(B.read(2,1,1)!=3)
       { return false; }

    C=A+B;
    if(C!=dodawanie)
       { return false; }

    C=A-B;
    if(C!=odejmowanie)
       { return false; }

    C=A*B;
    if(C!=mnozenie)
       { return false; }

    A+=B;
    if(A!=dodawanie)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

bool test2()
{
    /* TEST LICZB ZESPOLONYCH */

    Tensor< complex<int> > A(2,2,2);  /* tensor testowy */
    Tensor< complex<int> > B(2,2,2);  /* tensor testowy */
    Tensor< complex<int> > C(2,2,2);  /* pomocniczy tensor testowy */

    Tensor< complex<int> > dodawanie(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor< complex<int> > odejmowanie(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */
    Tensor< complex<int> > mnozenie(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */

    A.change(1,1,1, (3,1));
    A.change(1,1,2, (4,2));
    A.change(1,2,1, (0,1));
    A.change(1,2,2, (5,0));
    A.change(2,1,1, (-3,8));
    A.change(2,1,2, (5,2));
    A.change(2,2,1, (3,9));
    A.change(2,2,2, (0,0));
    
    cout<<A<<endl;

    B.change(1,1,1, (7,4));
    B.change(1,1,2, (-2,-1));
    B.change(1,2,1, (5,1));
    B.change(1,2,2, (1,2));
    B.change(2,1,1, (0,0));
    B.change(2,1,2, (1,0));
    B.change(2,2,1, (0,1));
    B.change(2,2,2, (0,0));

    cout<<B<<endl;

    dodawanie.change(1,1,1, (10,5));
    dodawanie.change(1,1,2, (2,1));
    dodawanie.change(1,2,1, (5,2));
    dodawanie.change(1,2,2, (6,2));
    dodawanie.change(2,1,1, (-3,8));
    dodawanie.change(2,1,2, (6,2));
    dodawanie.change(2,2,1, (3,10));
    dodawanie.change(2,2,2, (0,0));

    odejmowanie.change(1,1,1, (-4,-3));
    odejmowanie.change(1,1,2, (6,3));
    odejmowanie.change(1,2,1, (-5,0));
    odejmowanie.change(1,2,2, (4,-2));
    odejmowanie.change(2,1,1, (-3,8));
    odejmowanie.change(2,1,2, (4,2));
    odejmowanie.change(2,2,1, (3,8));
    odejmowanie.change(2,2,2, (0,0));

    mnozenie.change(1,1,1, (3,1)*(7,4));
    mnozenie.change(1,1,2, (4,2)*(-2,-1));
    mnozenie.change(1,2,1, (0,1)*(5,1));
    mnozenie.change(1,2,2, (5,0)*(1,2));
    mnozenie.change(2,1,1, (-3,8)*(0,0));
    mnozenie.change(2,1,2, (5,2)*(1,0));
    mnozenie.change(2,2,1, (3,9)*(0,1));
    mnozenie.change(2,2,2, (0,0)*(0,0));

    if(A.read(1,2,2)!=(5,0))
       { return false; }
    if(B.read(2,1,1)!=(0,0))
       { return false; }

    C=A+B;
    if(C!=dodawanie)
       { return false; }

    C=A-B;
    if(C!=odejmowanie)
       { return false; }

    C=A*B;
    if(C!=mnozenie)
       { return false; }

    A+=B;
    if(A!=dodawanie)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}