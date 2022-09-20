/**
 * @file unit_tests.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "unit_tests.hpp"

/**
 * @brief Run Unit Tests Globals
 * 
 * Calls unit and functional tests functions
 */
void run_unit_tests_globals(){
    cout << "----------------------------------" << endl;
    cout << "Unit System tests:" << endl << endl;

    run_unit_test_System();

    cout << endl << "OK" << endl;

    cout << "----------------------------------" << endl;
    cout << "Unit Flow tests:" << endl << endl;

    run_unit_test_Flow();

    cout << endl << "OK" << endl;

    cout << "----------------------------------" << endl;
    cout << "Unit Model tests:" << endl << endl;

    run_unit_test_Model();

    cout << endl << "OK" << endl;

    cout << "----------------------------------" << endl;

    cout << "All tests executed" << endl;
}