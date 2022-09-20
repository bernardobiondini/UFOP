/**
 * @file unit_Model.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_Model.hpp"
/**
 * @brief UNit Model COnstructor Test
 * 
 */
void unit_Model_constructor(){
    cout << "Model Constructor Test" << endl;
    /*!< Assert if all the Model's constructors work */
    ImpModel mod;
    assert(mod.getName() == "");
    /*!< Asserting the model copy constructor */
    ImpModel mod2(mod);
    assert(mod2.getName() == "");
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
    ImpModel mod;
    assert(mod.getName() == "");
}
/**
 * @brief Unit Model SetName test
 * 
 */
void unit_Model_setName(){
    cout << "Model Test Set Name";
    /*!< Assert if the setName method works */
    ImpModel *mod = new ImpModel();
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
    Model *mod = new ImpModel();
    System *s1 = new ImpSystem("system 1", 100);
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("fluxo 1", s1, s2);
    Flow *f2 = new Exponential("fluxo 2", s2, s1);

    mod->add(s1);
    mod->add(s2);
    
    assert((*(mod->getBeginSystems())) == s1);
    assert((*(--mod->getEndSystems())) == s2); /*!< The end iterator actually points to a non vector part */
    /*!< that's why -- before */
    mod->add(f1);
    mod->add(f2);

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
    Model *mod = new ImpModel();
    System *s1 = new ImpSystem("system 1", 100);
    System *s2 = new ImpSystem("system 2", 30);
    Flow *f1 = new Exponential("fluxo 1", s1, s2);
    Flow *f2 = new Exponential("fluxo 2", s2, s1);

    mod->add(s1);
    mod->add(s2);
    
    assert((*(mod->getBeginSystems()))->getName() == s1->getName());
    assert((*(mod->getBeginSystems()))->getValue() == s1->getValue());

    assert((*(++mod->getBeginSystems()))->getName() == s2->getName());
    assert((*(++mod->getBeginSystems()))->getValue() == s2->getValue());
    
    mod->add(f1);
    mod->add(f2);

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
    Model* model = new ImpModel(); 
    System* pop1 = new ImpSystem("pop1", 100); 
    System* pop2 = new ImpSystem("pop2", 0); 
    Flow* exponential = new Exponential("Exponential", pop1, pop2); 
    
    model->add(pop1); 
    model->add(pop2); 
    model->add(exponential); 
    model->execute(0, 100, 1);
    /*!< Similar to the functional test */

    assert(abs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(abs(pop2->getValue() - 63.3968) < 0.0001); 

    delete model;
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