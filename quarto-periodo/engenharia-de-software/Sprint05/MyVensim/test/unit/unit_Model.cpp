/**
 * @file unit_Model.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_Model.hpp"
/**
 * @brief Unit Model COnstructor Test
 * 
 */
void unit_Model_constructor(){
    cout << "Model Constructor Test" << endl;
    /*!< Assert if all the Model's constructors work */
    Model *mod = Model::createModel();
    assert(mod->getName() == "");
}
/**
 * @brief 
 * 
 */
void unit_Model_destructor(){

}
/**
 * @brief Unit Model GetName Test
 * 
 */
void unit_Model_getName(){
    cout << "Model GetName Test" << endl;
    /*!< Assert if the getName method works */
    Model *mod = Model::createModel();
    assert(mod->getName() == "");
}
/**
 * @brief Unit Model SetName test
 * 
 */
void unit_Model_setName(){
    cout << "Model Test Set Name" << endl;
    /*!< Assert if the setName method works */
    Model *mod = Model::createModel();
    mod->setName("model");

    assert(mod->getName() == "model");
}
/**                                                                                                                                                                                                                                                                                                                                                        
 * @brief Unit Model GetEnd GetBegin Tests
 * 
 */
void unit_Model_getBeginEnd(){
    cout << "Model GetEnd and GetBegin Test" << endl;
    /*!< Assert if the get end and get begin methods work */
    Model *mod = Model::createModel();
    System *s1 = mod->createSystem("system 1", 100);
    System *s2 = mod->createSystem("system 2", 30);
    Flow *f1 = mod->createFlow<UnitExponential>("fluxo 1", s1, s2);
    Flow *f2 = mod->createFlow<UnitExponential>("fluxo 2", s2, s1);
    
    assert((*(mod->getBeginSystems())) == s1);
    assert((*(--mod->getEndSystems())) == s2); /*!< The end iterator actually points to a non vector part */
    /*!< that's why -- before */

    assert((*(mod->getBeginFlows())) == f1);
    assert((*(--mod->getEndFlows())) == f2);

    delete mod;
}

/**
 * @brief Unit Model Add test
 * 
 */
void unit_Model_add(){
    cout << "Model Add Test" << endl;
    /*!< Asserts the add method                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 */
    Model *mod = Model::createModel();
    System *s1 = mod->createSystem("system 1", 100);
    System *s2 = mod->createSystem("system 2", 30);
    Flow *f1 = mod->createFlow<UnitExponential>("fluxo 1", s1, s2);
    Flow *f2 = mod->createFlow<UnitExponential>("fluxo 2", s2, s1);
    
    assert((*(mod->getBeginSystems()))->getName() == s1->getName());
    assert((*(mod->getBeginSystems()))->getValue() == s1->getValue());

    assert((*(++mod->getBeginSystems()))->getName() == s2->getName());
    assert((*(++mod->getBeginSystems()))->getValue() == s2->getValue());

    assert((*(mod->getBeginFlows()))->getName() == f1->getName());
    assert((*(mod->getBeginFlows()))->getSource() == f1->getSource());
    assert((*(mod->getBeginFlows()))->getTarget() == f1->getTarget());

    assert((*(++mod->getBeginFlows()))->getName() == f2->getName());
    assert((*(++mod->getBeginFlows()))->getSource() == f2->getSource());
    assert((*(++mod->getBeginFlows()))->getTarget() == f2->getTarget());

    delete mod;
}

/**
 * @brief UNit Model Execute Test
 * 
 */
void unit_Model_execute(){
    cout << "Model Execute Test" << endl;
    /*!< Asserts the execute method */
    Model *mod = Model::createModel();
    System *pop1 = mod->createSystem("pop 1", 100);
    System *pop2 = mod->createSystem("pop 2", 0);
    Flow *f1 = mod->createFlow<UnitExponential>("fluxo 1", pop1, pop2);

    mod->run(0, 100, 1);
    /*!< Similar to the functional test */
    assert(abs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(abs(pop2->getValue() - 63.3968) < 0.0001); 
}
/**
 * @brief 
 * 
 */
void run_unit_test_Model(){
    unit_Model_constructor();

    unit_Model_destructor();

    unit_Model_getName();

    unit_Model_setName();
        
    unit_Model_getBeginEnd();

    unit_Model_add();

    unit_Model_execute();
}