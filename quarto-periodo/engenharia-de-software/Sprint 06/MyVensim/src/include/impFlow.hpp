/**
 * @file impFlow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef impFlow_hpp
#define impFlow_hpp

#define POP_MAX 70

#include "flow.hpp"
#include "bridge.hpp"

using namespace std;

/** 
 * @brief ImpFlow Class.
 * 
 * Implementation class of Flow Interface.
 * Parent class, responsible for letting the children aplies some method under the value 
 * of the source system so the target system can receive the returned value.
 */
class FlowBody: public Body{
    protected:
        string name; /*!< Flow name */
        double currentValue; /*! Actual value of flow */
        System* source; /*!< Source system */
        System* target; /*!< Target System */

    private:
        /**
         * @brief Assignment Operator
         * 
         * @param flow 
         * @return FlowBody* 
         */
        FlowBody* operator=(const FlowBody* flow);

        /**
         * @brief Construct a new Flow Body object
         * 
         * @param flow 
         */
        FlowBody(const FlowBody* flow);
    
    public:
        /**
         * @brief FlowBody Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        FlowBody();
        /** 
         * @brief FlowBody Copy Constructor.
         * 
         * Following the Canonical Class Form 
         * @param copy make a copy of another flow
         */
        FlowBody(FlowBody &copy);
        /** 
         * @brief FlowBody Constructor parameters of string, System and System.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name name of the flow
         * @param source input system of the flow
         * @param target output system of the flow
         */
        FlowBody(string name, System* source, System* target);

        /** 
         * @brief Virtual FlowBody Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~FlowBody(){}

        /** 
         * @brief FlowBody Get Name Method.
         * 
         * Returns the flow's name
         * @return string
         */
        string getName() const;
        /** 
         * @brief FlowBody Get Source Method.
         * 
         * Returns the source system of the flow
         * @return System
         */
        System* getSource() const;
        /** 
         * @brief FlowBody Get Target Method.
         * 
         * Returns the target system of the flow
         * @return System
         */
        System* getTarget()const;

        /** 
         * @brief FlowBody Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to flow's name
         * @param name name of the flow
         */
        void setName(string name);
        /**
         * @brief FlowBody Set Source System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's source
         * @param source input system of the flow
         */
        void setSource(System* source);
        /**
         * @brief FlowBody Set Target System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's target
         * @param target output system of the flow
         */
        void setTarget(System* target);

        /** 
         * @brief FlowBody Conect Method.
         * 
         * Receive two Systems as parameters and attributes it to flow's source and flowś target
         * @param source input system of the flow
         * @param target output system of the flow
         */
        void conect(System *, System *);

        /** 
         * @brief Virtual FlowBody Execute Method.
         * 
         * This method will be implemented by class's children. It's responsible for 
         * return the value which the target system will receive considering the value that 
         * the source contains
         * @return double is going to be used to modify a value
         */
        virtual double execute() const = 0;
};

template <typename F_IMPL>
class FlowHandle : public Handle<F_IMPL>, public Flow {
    public:
        /**
         * @brief Construct a new FlowHandle<F_IMPL> object
         * 
         * @param name 
         * @param s 
         * @param t 
         */
        FlowHandle<F_IMPL>(string name = "", System *s = NULL, System *t = NULL){
            this->pImpl_->setName(name);
            this->pImpl_->setSource(s);
            this->pImpl_->setTarget(t);
        }

        /**
         * @brief Destroy the Flow Handle object
         * 
         */
        virtual ~FlowHandle(){};

        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName() const {
            return this->pImpl_->getName();
        }

        /**
         * @brief Set the Name object
         * 
         * @param name 
         */
        void setName(string name) {
            this->pImpl_->setName(name);
        }

        /**
         * @brief Get the Source object
         * 
         * @return System* 
         */
        System * getSource(void) const {
            return this->pImpl_->getSource();
        }

        /**
         * @brief Get the Target object
         * 
         * @return System* 
         */
        System * getTarget(void) const {
            return this->pImpl_->getTarget();
        }

        /**
         * @brief Set the Source object
         * 
         * @param source 
         */
        void setSource(System * source) {
        this->pImpl_->setSource(source);
        }

        /**
         * @brief Set the Target object
         * 
         * @param target 
         */
        void setTarget(System * target) {
            this->pImpl_->setTarget(target);
        }

        /**
         * @brief Conect Method
         * 
         * Receive two Systems as parameters and attributes it to flow's source and flowś target
         * @param source 
         * @param target 
         */
        void conect(System *source = NULL, System* target = NULL) {
            this->pImpl_->conect(source, target);
        }

        /**
         * @brief Execute Method
         * 
         * @return double 
         */
        double execute() const  {
            return this->pImpl_->execute();
        }

};

#endif