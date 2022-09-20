/**
 * @file functional_tests.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "functional_tests.hpp"

/**
 * @brief Functional Exponential Test Function.
 * 
 * Verify if the dynamics of the model when the Exponential flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalExponentialTest(){
    Model* model = new ImpModel(); /*!< Instance model */

    System* pop1 = new ImpSystem("pop1", 100); /*!< Instance system (pop1) */
    System* pop2 = new ImpSystem("pop2", 0); /*!< Instance system (pop2) */
    Flow* exponential = new Exponential("Exponential", pop1, pop2); /*!< Instance Exponential flow with pop1 and pop2 as System, source and target */
    
    model->add(pop1); /*!< Add pop1 system to model systems */
    model->add(pop2); /*!< Add pop2 system to model systems */
    model->add(exponential); /*!< Add exponential flow to model flows */
    model->execute(0, 100, 1); /*!< Calls execute method to execute the model dynamics */

    assert(abs(pop1->getValue() - 36.6032) < 0.0001); /*!< Assert value */
    assert(abs(pop2->getValue() - 63.3968) < 0.0001); /*!< Assert value */

    delete model;
}

/**
 * @brief Functional Logistical Test Function.
 * 
 * Verify if the dynamics of the model when the Logistical flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalLogisticalTest(){
    Model* model = new ImpModel(); /*!< Instance model */

    System* pop1 = new ImpSystem("pop1", 100); /*!< Instance system (pop1) */
    System* pop2 = new ImpSystem("pop2", 10); /*!< Instance system (pop2) */
    Flow *logistical = new Logistical("Logistical", pop1, pop2); /*!< Instance Logistical flow with pop1 and pop2 as System, source and target */

    model->add(pop1); /*!< Add pop1 system to model systems */
    model->add(pop2); /*!< Add pop2 system to model systems */
    model->add(logistical); /*!< Add logistical flow to model flows */
    model->execute(0, 100, 1); /*!< Calls execute method to execute the model dynamics */

    assert(abs(pop1->getValue() - 88.2167) < 0.0001); /*!< Assert value */
    assert(abs(pop2->getValue() - 21.7833) < 0.0001); /*!< Assert value */

    delete model;
}

/**
 * @brief Functional Complex Test Function.
 * 
 * Verify if the dynamics of the model when the Complex flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalComplexTest(){
    Model *model = new ImpModel();

    System *sys1, *sys2, *sys3, *sys4, *sys5;
    Flow *f1, *f2, *f3, *f4, *f5, *f6;

    /**
     * @brief Instance Systems
     * 
     */
    sys1 = new ImpSystem("sys1", 100);
    sys2 = new ImpSystem("sys2", 0);
    sys3 = new ImpSystem("sys3", 100);
    sys4 = new ImpSystem("sys4", 0);
    sys5 = new ImpSystem("sys5", 0);

    /**
     * @brief Instance Complex Flows
     * 
     */
    f1 = new Complex("f", sys1, sys2);
    f2 = new Complex("r", sys2, sys5);
    f3 = new Complex("f", sys2, sys3);
    f4 = new Complex("g", sys1, sys3);
    f5 = new Complex("u", sys3, sys4);
    f6 = new Complex("v", sys4, sys1);

    /**
     * @brief Add Systems
     * 
     */
    model->add(sys1);
    model->add(sys2);
    model->add(sys3);
    model->add(sys4);
    model->add(sys5);
    
    /**
     * @brief Add Flows
     * 
     */
    model->add(f1);
    model->add(f2);
    model->add(f3);
    model->add(f5);
    model->add(f4);
    model->add(f6);

    model->execute(0, 100, 1); /*!< Calls execute method to execute the model dynamics */

    assert(abs(sys1->getValue() - 31.8513) < 0.0001); /*!< Assert value */
    assert(abs(sys2->getValue() - 18.4003) < 0.0001); /*!< Assert value */
    assert(abs(sys3->getValue() - 77.1143) < 0.0001); /*!< Assert value */
    assert(abs(sys4->getValue() - 56.1728) < 0.0001); /*!< Assert value */
    assert(abs(sys5->getValue() - 16.4612) < 0.0001); /*!< Assert value */

    delete model;
}