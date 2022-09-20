/**
 * @file functional_tests.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef functional_tests_hpp
#define functional_tests_hpp

#include "../../src/include/system.hpp"
#include "../../src/include/flow.hpp"
#include "../../src/include/model.hpp"

#include <assert.h>

/** 
 * @brief Exponential Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Exponential: public ImpFlow{
    public:
        /**
         * @brief Exponential Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Exponential(string name, System *source, System *target);

        /**
         * @brief Exponential Destructor.
         * 
         */
        ~Exponential(){}
        
        /**
         * @brief Exponential Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

/** 
 * @brief Logistical Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Logistical: public ImpFlow{
    public:
        /**
         * @brief Logistical Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Logistical(string name, System *source, System *target);

        /**
         * @brief Logistical Destructor.
         * 
         */
        ~Logistical(){}
        
        /**
         * @brief Logistical Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

/** 
 * @brief Complex Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Complex: public ImpFlow{
    public:
        /**
         * @brief Complex Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Complex(string name, System *source, System *target);

        /**
         * @brief Complex Destructor.
         * 
         */
        ~Complex(){}
        
        /**
         * @brief Complex Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};


/**
 * @brief Functional Exponential Test Function.
 * 
 * Verify if the dynamics of the model when the Exponential flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalExponentialTest();

/**
 * @brief Functional Logistical Test Function.
 * 
 * Verify if the dynamics of the model when the Logistical flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalLogisticalTest();

/**
 * @brief Functional Complex Test Function.
 * 
 * Verify if the dynamics of the model when the Complex flow is used works. It's 
 * verified by assert function to guarantee the results.
 */
void functionalComplexTest();

#endif