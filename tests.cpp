#include <iostream>
#include <typeinfo>
#include <complex>
#include "tests.h"
#include "tensor.h"

using namespace std;

void test(){
    if(test_1()) cout<<"test_1: PASS"<<endl;
    else cout<<"test_1: FAIL"<<endl;

    if(test_2()) cout<<"test_1: PASS"<<endl;
    else cout<<"test_1: FAIL"<<endl;

    if(test_3()) cout<<"test_1: PASS"<<endl;
    else cout<<"test_1: FAIL"<<endl;

    if(test_4()) cout<<"test_1: PASS"<<endl;
    else cout<<"test_1: FAIL"<<endl;

    if(test_5()) cout<<"test_1: PASS"<<endl;
    else cout<<"test_1: FAIL"<<endl;
}