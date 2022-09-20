/**
 * @file unit_System.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_System.hpp"

/**
 * @brief Unit System Constructor Test
 * 
 */
void unit_System_constructor(){
    cout << "System Constructor Test" << endl;
    /*!< Asserts all the System's constructors */
    SystemBody s1;
    assert( s1.getName() == "" );
    assert( s1.getValue() == 0 );

    SystemBody s2("nome", 10);
    assert( s2.getName() == "nome");
    assert( s2.getValue() == 10 );
}

void unit_System_destructor(){

}

/**
 * @brief Unit System GetName Test
 * 
 */
void unit_System_getName(){
    cout << "System GetName Test" << endl;
    /*!< Asserts the getName method works */
    SystemBody s1;
    assert( s1.getName() == "" );

    SystemBody s2("nome", 10);
    assert( s2.getName() == "nome");
}
/**
 * @brief Unit System GetValue Test
 * 
 */
void unit_System_getValue(){
    cout << "System GetValue Test" << endl;
    /*!< Asserts if the getValue method works */
    SystemBody s1;
    assert( s1.getValue() == 0 );

    SystemBody s2("nome", 10);
    assert( s2.getValue() == 10 );
}
/**
 * @brief Unit System SetName Test
 * 
 */
void unit_System_setName(){
    cout << "System SetName Test" << endl;
    /*!< Asserts if the setName method works */
    SystemBody s1;
    s1.setName("system");
    assert(s1.getName() == "system");
}
/**
 * @brief Unit System SetValue Test
 * 
 */
void unit_System_setValue(){
    cout << "System SetValue Test" << endl;
    /*!< Asserts if the setValue method works */
    SystemBody s1;
    s1.setValue(20);
    assert(s1.getValue() == 20);
}

void run_unit_test_System(){
    unit_System_constructor();

    unit_System_destructor();

    unit_System_getName();

    unit_System_getValue();

    unit_System_setName();

    unit_System_setValue();
}