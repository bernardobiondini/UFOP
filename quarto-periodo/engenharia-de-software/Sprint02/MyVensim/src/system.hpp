#ifndef system_hpp
#define system_hpp

#include <iostream>
#include <string>
using namespace std;

class System{
    protected:
        string name;
        double value;
    public:
        System();
        virtual ~System(){}

        System(System&);
        System(string, double);

        string getName() const;
        double getValue() const;

        void setName(string);
        void setValue(double);

        System& operator=(System&);
};

#endif