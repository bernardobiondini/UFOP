#include "functional_tests.hpp"

int main(){
    cout << "----------------------------------" << endl;
    cout << "Functional Exponential test:" << endl;

    functionalExponentialTest();

    cout << endl << "OK" << endl;

    cout << "----------------------------------" << endl;
    cout << "Functional Logistical test:" << endl;

    functionalLogisticalTest();

    cout << endl << "OK" << endl;

    cout << "----------------------------------" << endl;
    cout << "Functional Complex test:" << endl;

    functionalComplexTest();

    cout << endl << "OK" << endl;
}