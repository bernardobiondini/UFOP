/**
 * @file uni_Flow.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_Flow.hpp"

/**
 * @brief Unit Flow Constructor Test
 * 
 * Assert if all the flow's constructors work.
 */
void unit_Flow_constructor(){
    cout << "Flow Constructor Test" << endl;

    /*!< Instance 2 objects of system and conect it by flow's source and target */
    ImpSystem s1;
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("flow1", &s1, s2);

    /*!< assert if the results are correct */
    assert(f1->getName() == "flow1");
    assert(f1->getSource() == &s1);
    assert(f1->getTarget() == s2);

    /*!< Assert copy constructor */
    Flow *f2(f1);

    assert(f1 == f2);
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
    Flow *f1 = new Exponential("flow1", NULL, NULL);

    assert(f1->getName() == "flow1");
}

/**
 * @brief Unit Flow GetSource Test
 * 
 */
void unit_Flow_getSource(){
    cout << "Flow GetSource Test" << endl;
    /*!< Checking if the source is equal to Instance we created */
    ImpSystem s1;
    Flow *f1 = new Exponential("", &s1, NULL);

    assert(f1->getSource() == &s1);
}

/**
 * @brief Unit Flow GetTarget Test
 * 
 */
void unit_Flow_getTarget(){
    cout << "Flow GetTarget Test" << endl;
    /*!< Checking if the target is equal to Instance we created */
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("", NULL, s2);

    assert(f1->getTarget() == s2);
}

/**
 * @brief Unit Flow SetName Test
 * 
 */
void unit_Flow_setName(){
    cout << "Flow SetName Test" << endl;
    /*!< Assert if the setName method works */
    Exponential f1("", NULL, NULL);

    f1.setName("exponential");
    assert(f1.getName() == "exponential");
}

/**
 * @brief Unit Flow SetSource Test
 * 
 */
void unit_Flow_setSource(){
    cout << "Flow SetSource Test" << endl;
    /*!< Asssert if the setSource method works */
    ImpSystem s1;
    Flow *f1 = new Exponential("", NULL, NULL);

    f1->setSource(&s1);

    assert(f1->getSource() == &s1);
}

/**
 * @brief Unit Flow SetTarget Test
 * 
 */
void unit_Flow_setTarget(){
    cout << "Flow SetTarget Test" << endl;
    /*!< Assert if the setTarget works */
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("", NULL, NULL);

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
    ImpSystem s1;
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("", NULL, NULL);

    f1->conect(&s1, s2);

    assert(f1->getSource() == &s1);
    assert(f1->getTarget() == s2);
}

/**
 * @brief Unit Flow Execute Test
 * 
 */
void unit_Flow_execute(){
    cout << "Flow execute Test" << endl;
    /*!< Asserct if the execute method returns the expected result */
    System* system1 = new ImpSystem("System 1", 100.0);
    System* system2 = new ImpSystem("System 2", 0.0);
    Exponential* flow = new Exponential("Flow", system1, system2);

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