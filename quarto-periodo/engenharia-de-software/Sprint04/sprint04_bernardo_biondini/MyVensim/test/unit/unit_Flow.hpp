/**
 * @file unit_Flow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef unit_Flow_hpp
#define unit_Flow_hpp

#include "unit_System.hpp"

#include "../../src/impFlow.hpp"
#include "../../src/impSystem.hpp"

/**
 * @brief Unit Flow Constructor Test
 * 
 */
void unit_Flow_constructor();

/**
 * @brief Unit Flow Destructor Test
 * 
 */
void unit_Flow_destructor();
/**
 * @brief Unit Flow GetName Test
 * 
 */
void unit_Flow_getName();

/**
 * @brief Unit Flow GetSource Test
 * 
 */
void unit_Flow_getSource();

/**
 * @brief Unit Flow GetTarget Test
 * 
 */
void unit_Flow_getTarget();

/**
 * @brief Unit Flow SetName Test
 * 
 */
void unit_Flow_setName();

/**
 * @brief Unit Flow SetSource Test
 * 
 */
void unit_Flow_setSource();

/**
 * @brief Unit Flow SetTarget Test
 * 
 */
void unit_Flow_setTarget();

/**
 * @brief Unit Flow Conect Test
 * 
 */
void unit_Flow_conect();

/**
 * @brief Unit Flow Execute Test
 * 
 */
void unit_Flow_execute();

/**
 * @brief Unit Flow Tests
 * 
 */
void run_unit_test_Flow();

#endif