/**
 * @file model.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef model_hpp
#define model_hpp

#include <vector>
#include <iostream>

#include "flow.hpp"

/** 
 * @brief Model Class.
 * 
 * Represents a set of System(s) and/or Flow(s). It's responsible for execution and for set
 * up the operation and workflow of values.
 */
class Model{
    protected:
        vector<System*> systems; /*!< Vector of Systems */
        vector<Flow*> flows; /*!< Vector of Flows */
        string name; /*!< Model name */
    public:  
        /**
         * @brief Model Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        Model();

        /**
         * @brief Model Copy Constructor.
         * 
         * Following the Canonical Class Form
         * @param copy make a copy of another model
         */
        Model(Model &copy);

        /**
         * @brief Virtual Model Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~Model();      

        /**
         * @brief Model Get Name Method.
         * 
         * Returns the model's name
         * @return string 
         */
        string getName() const;
        
        /**
         * @brief Model Set Vector of Flows Method.
         * 
         * Receives a vector of Flows as parameter and attributes it to flows
         * @param newFlows vector of Flows
         */
        void setFlows(vector<Flow*> newFlows);

        /**
         * @brief Model Set Vector of Systems Method.
         * 
         * Receives a vector of Systems as parameter and attributes it to systems
         * @param newSystems vector of Systems
         */
        void setSystems(vector<System*> newSystems);

        /**
         * @brief Model Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a System or a Flow
         * @param System push a System into the System vector
         */
        void add(System *system);

        /**
         * @brief Model Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a Flow or a System
         * @param System push a Flow into the Flow vector
         */
        void add(Flow *flow);

        /**
         * @brief Model Execute Method.
         * @warning Execute method is the main method of Model,responsible
         * for controlling the flow and the results of Model's dynamics
         * @param initial_time 
         * @param final_time 
         * @param incr how much the program will increment, simulates time
         */
        void execute(double initial_time, double final_time, int incr);

        /**
         * @brief Model Assignment Operator.
         * 
         * Following the Canonical Class Form
         * @param model
         * @return Model& 
         */
        Model& operator=(Model &model);
};

#endif