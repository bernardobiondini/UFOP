/**
 * @file functional_tests.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef functional_tests_hpp
#define functional_tests_hpp

#include "../../src/impSystem.hpp"
#include "../../src/impFlow.hpp"
#include "../../src/impModel.hpp"

#include <assert.h>
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