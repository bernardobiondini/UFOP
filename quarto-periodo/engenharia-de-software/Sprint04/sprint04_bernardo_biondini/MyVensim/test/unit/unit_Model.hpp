/**
 * @file unit_Model.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef unit_Model_hpp
#define unit_Model_hpp

#include <assert.h>

#include "unit_Flow.hpp"
#include "../../src/impModel.hpp"
#include "../../src/impFlow.hpp"
#include "../../src/impSystem.hpp"

void unit_Model_constructor();

void unit_Model_destructor();

void unit_Model_getName();
    
void unit_Model_getBeginEnd();

void unit_Model_setName();

void unit_Model_add();

void unit_Model_execute();

void run_unit_test_Model();

#endif