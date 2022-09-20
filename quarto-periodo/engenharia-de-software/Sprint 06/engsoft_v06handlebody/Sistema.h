
#if ! defined(SYSTEM_H)
#define SYSTEM_H

#include <iostream>

using namespace std;

class System{
  public: 
    virtual double getValue(void)   = 0;
    virtual string getName(void)    = 0;
};

#endif
