#ifndef flow_hpp
#define flow_hpp

#include "system.hpp"

using namespace std;

class Flow{
    protected:
        string name;
        System* source;
        System* target;
    
    public:
        Flow();
        virtual ~Flow(){}
        Flow(string, System*, System*);
        Flow(Flow&);

        string getName() const;
        System* getSource() const;
        System* getTarget()const;

        void setName(string);
        void setSource(System*);
        void setTarget(System*);

        void conect(System *, System *);

        virtual double execute() const = 0;

        Flow& operator=(Flow&);
};

#endif