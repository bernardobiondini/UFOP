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
#include "bridge.hpp"

/** 
 * @brief ModelBody Class.
 * 
 * Implementation class of Model Interface.
 * Represents a set of System(s) and/or Flow(s). It's responsible for execution and for set
 * up the operation and workflow of values.
 */
class ModelBody: public Body{
    protected:
        vector<System*> systems; /*!< Vector of Systems */
        vector<Flow*> flows; /*!< Vector of Flows */
        string name; /*!< Model name */
        static vector<Model*> models;

    private:
        /**
         * @brief ModelBody Assignment Operator.
         * 
         * Following the Canonical Class Form
         * @param model
         * @return ModelBody& 
         */
        ModelBody& operator=(ModelBody &model);

        /**
         * @brief ModelBody Copy Constructor.
         * 
         * Following the Canonical Class Form
         * @param copy make a copy of another model
         */
        ModelBody(ModelBody &copy);

    public:
        /**
         * @brief ModelBody Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        ModelBody();
        

        /**
         * @brief ModelBody Destructor.
         * 
         * Following the Canonical Class Form
         */
        ~ModelBody();  

        /**
         * @brief ModelBody Get Name Method.
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
         * @brief ModelBody Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to model's name
         * @param name name of the model
         */
        void setName(string name);

         /**
         * @brief ModelBody Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a System or a Flow
         * @param System push a System into the System vector
         */
        void add(System *system);

        /**
         * @brief ModelBody Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a Flow or a System
         * @param System push a Flow into the Flow vector
         */
        void add(Flow *flow);

        /**
         * @brief ModelBody Execute Method.
         * @warning Execute method is the main method of Model,responsible
         * for controlling the flow and the results of Model's dynamics
         * @param initial_time 
         * @param final_time 
         * @param incr how much the program will increment, simulates time
         */
        void run(double initial_time, double final_time, int incr);

        System* createSystem(string name, double value);

        static Model* createModel();
};

/**
 * @brief Class Model
 * 
 * Concrete Class, represents the general model of the simulation
 */
class ModelHandle : public Handle<ModelBody>, public Model {
protected:
    
    /**
     * @brief ModelBody Add Method.
     * 
     * This method uses Overloading concept, wether the parameter is a Flow or a System
     * @param System push a Flow into the Flow vector
     */
    void add(Flow * flow = NULL) {
        pImpl_->add(flow);
    }

    /**
     * @brief ModelBody Add Method.
     * 
     * This method uses Overloading concept, wether the parameter is a Flow or a System
     * @param System push a Flow into the Flow vector
     */
    void add(System * system = NULL){
        pImpl_->add(system);
    }
public:
    /**
     * @brief Construct a new Model Handle object
     * 
     */
    ModelHandle() {
        pImpl_->setName("");
    }

    /**
     * @brief Construct a new Model Handle object
     * 
     * @param name 
     */
    ModelHandle(string name) {
        pImpl_->setName(name);
    }

    /**
     * @brief Create a Model object
     * 
     * Model fabric objects
     * @return Model* 
     */
    static Model * createModel() {
        return ModelBody::createModel();
    }

    /**
     * @brief Destroy the Model Handle object
     * 
     */
    virtual ~ModelHandle(){}
    
    /**
     * @brief 
     * 
     * @return flowIterator 
     */
    flowIterator getBeginFlows() {
        return pImpl_->getBeginFlows();
    }

    /**
     * @brief 
     * 
     * @return flowIterator 
     */
    flowIterator getEndFlows() {
        return pImpl_->getEndFlows();
    }

    /**
     * @brief 
     * 
     * @return systemIterator 
     */
    systemIterator getBeginSystems() {
        return pImpl_->getBeginSystems();
    }

    /**
     * @brief 
     * 
     * @return systemIterator 
     */
    systemIterator getEndSystems() {
        return pImpl_->getEndSystems();
    }
    
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(string name) {
        pImpl_->setName(name);
    }

    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName() const {
        return pImpl_->getName();
    }

    /**
     * @brief Run Method
     * 
     * @param start 
     * @param end 
     * @param increment 
     */
    void run(double start, double end, int increment) {
        pImpl_->run(start, end, increment);
    }

    /**
     * @brief Create a System object
     * 
     * System Fabric
     * @param name 
     * @param value 
     * @return System* 
     */
    System* createSystem(string name, double value = 0) {
        return pImpl_->createSystem(name, value);
    }
};

#endif