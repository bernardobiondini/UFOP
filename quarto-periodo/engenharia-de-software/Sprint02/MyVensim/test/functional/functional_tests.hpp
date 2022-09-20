#ifndef functional_tests_hpp
#define functional_tests_hpp

#define POP_MAX 70

#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include "../../src/model.hpp"

#include <assert.h>

void functionalExponentialTest();
void functionalLogisticalTest();
void functionalComplexTest();

class Exponential: public Flow{
    public:
        Exponential(string, System*, System*);

        ~Exponential(){}

        double execute() const;
};


class Logistical: public Flow{
    public: 
        Logistical(string, System*, System*);

        ~Logistical(){}

        
        double execute() const;
};

class Complex: public Flow{
    public:
        Complex(string, System*, System*);
    
        ~Complex(){}

        double execute() const;
};

#endif