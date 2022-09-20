/**
 * @file unit_Flow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef unit_Flow_hpp
#define unit_Flow_hpp

#include "unit_System.hpp"

#include "../../src/include/impFlow.hpp"
#include "../../src/include/impSystem.hpp"

/** 
 * @brief UnitExponential Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class UnitExponential: public ImpFlow{
    public:
        /**
         * @brief UnitExponential Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        UnitExponential(string name, System *source, System *target);

        /**
         * @brief UnitExponential Destructor.
         * 
         */
        ~UnitExponential(){}
        
        /**
         * @brief UnitExponential Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

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