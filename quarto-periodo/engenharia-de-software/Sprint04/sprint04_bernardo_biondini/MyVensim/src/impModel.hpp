/**
 * @file impModel.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef impModel_hpp
#define impModel_hpp

#include <vector>
#include <iostream>

#include "model.hpp"

/** 
 * @brief ImpModel Class.
 * 
 * Implementation class of Model Interface.
 * Represents a set of System(s) and/or Flow(s). It's responsible for execution and for set
 * up the operation and workflow of values.
 */
class ImpModel: public Model{
    protected:
        vector<System*> systems; /*!< Vector of Systems */
        vector<Flow*> flows; /*!< Vector of Flows */
        string name; /*!< Model name */
    public:
        /**
         * @brief ImpModel Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        ImpModel();
        /**
         * @brief ImpModel Copy Constructor.
         * 
         * Following the Canonical Class Form
         * @param copy make a copy of another model
         */
        ImpModel(ImpModel &copy);

        /**
         * @brief ImpModel Destructor.
         * 
         * Following the Canonical Class Form
         */
        ~ImpModel();  

        /**
         * @brief ImpModel Get Name Method.
         * 
         * Returns the model's name
         * @return string 
         */
        string getName() const;

        /**
         * @brief System Iterator Typedef
         * 
         * Responsible for define a type for the Iterator
         */
        typedef vector<System*>::iterator systemIterator;

        /**
         * @brief Flow Iterator Typedef
         * 
         * Responsible for define a type for the Iterator
         */
        typedef vector<Flow*>::iterator flowIterator;

        /**
         * @brief Get the Begin Systems
         * 
         * Returns the Beginning of System's vector
         * @return systemIterator 
         */
        systemIterator getBeginSystems(); 

        /**
         * @brief Get the End Systems
         * 
         * Returns the Ending of System's vector
         * @return systemIterator 
         */
        systemIterator getEndSystems(); 

        /**
         * @brief Get the Begin Flows
         * 
         * Returns the Beginning of Flow's vector
         * @return flowIterator 
         */
        flowIterator getBeginFlows(); 

        /**
         * @brief Get the End Flows
         * 
         * Returns the Ending of Flow's vector
         * @return flowIterator 
         */
        flowIterator getEndFlows(); 

        /** 
         * @brief ImpModel Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to model's name
         * @param name name of the model
         */
        void setName(string name);

        /**
         * @brief ImpModel Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a System or a Flow
         * @param System push a System into the System vector
         */
        void add(System *system);

        /**
         * @brief ImpModel Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a Flow or a System
         * @param System push a Flow into the Flow vector
         */
        void add(Flow *flow);

        /**
         * @brief ImpModel Execute Method.
         * @warning Execute method is the main method of Model,responsible
         * for controlling the flow and the results of Model's dynamics
         * @param initial_time 
         * @param final_time 
         * @param incr how much the program will increment, simulates time
         */
        void execute(double initial_time, double final_time, int incr);

        /**
         * @brief ImpModel Assignment Operator.
         * 
         * Following the Canonical Class Form
         * @param model
         * @return ImpModel& 
         */
        ImpModel& operator=(ImpModel &model);
};

#endif