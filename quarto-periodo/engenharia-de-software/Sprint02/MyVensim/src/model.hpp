#ifndef model_hpp
#define model_hpp

#include <vector>
#include <iostream>

#include "flow.hpp"

class Model{
    protected:
        vector<System*> systems;
        vector<Flow*> flows;
        string name;
    public:    
        Model();
        virtual ~Model();    
        Model(Model&);    
        
        vector<System*>& getSystems();
        vector<Flow*>& getFlows();
        string getName() const;
        
        void setFlows(vector<Flow*>);
        void setSystems(vector<System*>);

        void add(System *);
        void add(Flow*);

        void execute(double initial_time, double final_time, int incr);

        Model& operator=(Model&);
};

#endif