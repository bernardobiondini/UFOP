#include "functional_tests.hpp"

Exponential::Exponential(string name, System* source, System* target)
                        : Flow(name, source, target){}

double Exponential::execute() const { 
    return 0.01 * this->source->getValue();
}


Logistical::Logistical(string name, System* source, System* target)
    : Flow(name, source, target){}

double Logistical::execute() const {
    return 0.01 * this->target->getValue() * (1 - (this->target->getValue() / POP_MAX));
}

Complex::Complex(string name, System *source, System *target)
    : Flow (name, source, target){}

double Complex::execute() const {
    return 0.01 * this->source->getValue();
}


void functionalExponentialTest(){
    Model* model = new Model();

    System* pop1 = new System("pop1", 100);
    System* pop2 = new System("pop2", 0);
    Flow* exponential = new Exponential("Exponential", pop1, pop2);
    
    model->add(pop1);
    model->add(pop2);
    model->add(exponential);
    model->execute(0, 100, 1);

    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);

    delete model;
}

void functionalLogisticalTest(){
    Model *model = new Model();
    System *pop1 = new System("pop1", 100);
    System *pop2 = new System("pop2", 10);
    Flow *logistical = new Logistical("Logistical", pop1, pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(logistical);
    model->execute(0, 100, 1);

    assert(abs(pop1->getValue() - 88.2167) < 0.0001);
    assert(abs(pop2->getValue() - 21.7833) < 0.0001);

    delete model;
}

void functionalComplexTest(){
    Model *model = new Model();

    System *sys1, *sys2, *sys3, *sys4, *sys5;
    Flow *f1, *f2, *f3, *f4, *f5, *f6;

    sys1 = new System("sys1", 100);
    sys2 = new System("sys2", 0);
    sys3 = new System("sys3", 100);
    sys4 = new System("sys4", 0);
    sys5 = new System("sys5", 0);

    f1 = new Complex("f", sys1, sys2);
    f2 = new Complex("r", sys2, sys5);
    f3 = new Complex("f", sys2, sys3);
    f4 = new Complex("g", sys1, sys3);
    f5 = new Complex("u", sys3, sys4);
    f6 = new Complex("v", sys4, sys1);

    // add systems
    model->add(sys1);
    model->add(sys2);
    model->add(sys3);
    model->add(sys4);
    model->add(sys5);
    // add flows
    model->add(f1);
    model->add(f2);
    model->add(f3);
    model->add(f5);
    model->add(f4);
    model->add(f6);

    model->execute(0, 100, 1);

    assert(abs(sys1->getValue() - 31.8513) < 0.0001);
    assert(abs(sys2->getValue() - 18.4003) < 0.0001);
    assert(abs(sys3->getValue() - 77.1143) < 0.0001);
    assert(abs(sys4->getValue() - 56.1728) < 0.0001);
    assert(abs(sys5->getValue() - 16.4612) < 0.0001);

    delete model;
}