/**
 * @file uni_Flow.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_Flow.hpp"

UnitExponential::UnitExponential(): FlowBody(){}

/**
 * @brief UnitExponential Constructor parameters of string, System and System
 * 
 * All of the attributes will receive its values from the parameters
 * @param name 
 * @param source 
 * @param target
 */
UnitExponential::UnitExponential(string name, System *s, System *t): 
                                    FlowBody(name, s, t){}

/**
 * @brief UnitExponential Overriding Execute Method.
 * 
 * Returns the value of source system multiplied by 0.01
 * @return double 
 */
double UnitExponential::execute() const { 
    return 0.01 * this->source->getValue();
}

/**
 * @brief Unit Flow Constructor Test
 * 
 * Assert if all the flow's constructors work.
 */
void unit_Flow_constructor(){
    cout << "Flow Constructor Test" << endl;

    /*!< Instance 2 objects of system and conect it by flow's source and target */
    Flow * f1 = new FlowHandle<UnitExponential>();
    assert(f1->getSource() == NULL);
    assert(f1->getTarget() == NULL);

    Flow *f2 = new FlowHandle<UnitExponential>("f2", NULL, NULL);
    assert(f2->getSource() == NULL);
    assert(f2->getTarget() == NULL);
    cout << "Ok!" << endl;
    
    // cout << "[Flow] - Construtor de copia: ";
    // Flow *f3 = new FlowHandle<UnitExponential>("f3");
    // Flow *f4 = new FlowHandle<UnitExponential>(f3);
    // assert(f4->getName() == f3->getName());

    delete f1;
    delete f2;
}

/**
 * @brief Unit Flow Destructor Test
 * 
 */
void unit_Flow_destructor(){

}

/**
 * @brief Unit Flow GetName Test
 * 
 */
void unit_Flow_getName(){
    cout << "Flow GetName Test" << endl;
    /*!< Instance a flow and check if its attributes are correct */
    Flow *f1 = new FlowHandle<UnitExponential>("flow1", NULL, NULL);

    assert(f1->getName() == "flow1");
}

/**
 * @brief Unit Flow GetSource Test
 * 
 */
void unit_Flow_getSource(){
    cout << "Flow GetSource Test" << endl;
    /*!< Checking if the source is equal to Instance we created */
    System *s1 = new SystemHandle("System 1", 100);
    Flow *f1 = new FlowHandle<UnitExponential>("", s1, NULL);

    assert(f1->getSource() == s1);
}

/**
 * @brief Unit Flow GetTarget Test
 * 
 */
void unit_Flow_getTarget(){
    cout << "Flow GetTarget Test" << endl;
    /*!< Checking if the target is equal to Instance we created */
    System *s1 = new SystemHandle("System 1", 100);
    Flow *f1 = new FlowHandle<UnitExponential>("", NULL, s1);

    assert(f1->getTarget() == s1);
}

/**
 * @brief Unit Flow SetName Test
 * 
 */
void unit_Flow_setName(){
    cout << "Flow SetName Test" << endl;
    /*!< Assert if the setName method works */
    UnitExponential f1("", NULL, NULL);

    f1.setName("Unitexponential");
    assert(f1.getName() == "Unitexponential");
}

/**
 * @brief Unit Flow SetSource Test
 * 
 */
void unit_Flow_setSource(){
    cout << "Flow SetSource Test" << endl;
    /*!< Asssert if the setSource method works */
    System *s1 = new SystemHandle("System 1", 100);
    Flow *f1 = new FlowHandle<UnitExponential>("", NULL, NULL);

    f1->setSource(s1);

    assert(f1->getSource() == s1);
}

/**
 * @brief Unit Flow SetTarget Test
 * 
 */
void unit_Flow_setTarget(){
    cout << "Flow SetTarget Test" << endl;
    /*!< Assert if the setTarget works */
    System *s2 = new SystemHandle("system 2", 30);
    Flow *f1 = new FlowHandle<UnitExponential>("", NULL, NULL);

    f1->setTarget(s2);

    assert(f1->getTarget() == s2);
}

/**
 * @brief Unit Flow Conect Test
 * 
 */
void unit_Flow_conect(){
    cout << "Flow Conect Test" << endl;
    /*!< Assert if the conect method really put a system on source and another in target */
    System *s1 = new SystemHandle("System 1", 100);
    System *s2 = new SystemHandle("system 2", 30);
    Flow *f1 = new FlowHandle<UnitExponential>("", NULL, NULL);

    f1->conect(s1, s2);

    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);
}

/**
 * @brief Unit Flow Execute Test
 * 
 */
void unit_Flow_execute(){
    cout << "Flow execute Test" << endl;
    /*!< Asserct if the execute method returns the expected result */
    System* system1 = new SystemHandle("System 1", 100.0);
    System* system2 = new SystemHandle("System 2", 0.0);
    Flow* flow = new FlowHandle<UnitExponential>("Flow", system1, system2);

    system2->setValue(flow->execute());
    
    assert(abs(flow->getTarget()->getValue() - 1) < 0.01);
}

/**
 * @brief Unit Flow Tests
 * 
 */
void run_unit_test_Flow(){

    unit_Flow_constructor();

    unit_Flow_destructor();

    unit_Flow_getName();

    unit_Flow_getSource();

    unit_Flow_getTarget();

    unit_Flow_setName();

    unit_Flow_setSource();

    unit_Flow_setTarget();

    unit_Flow_conect();

    unit_Flow_execute();
}