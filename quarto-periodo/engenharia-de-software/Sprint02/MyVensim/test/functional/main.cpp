#include "functional_tests.hpp"

int main(){
    
    functionalExponentialTest();
    cout << endl << "Exponential test executed" << endl;
    functionalLogisticalTest();
    cout << "Logic test executed" << endl;
    functionalComplexTest();
    cout << "Complex test executed" << endl << endl;

    cout << "All tests executed" << endl;
    return 0;
}