/**
 * @file impFlow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef impFlow_hpp
#define impFlow_hpp

#define POP_MAX 70

#include "flow.hpp"

using namespace std;

/** 
 * @brief ImpFlow Class.
 * 
 * Implementation class of Flow Interface.
 * Parent class, responsible for letting the children aplies some method under the value 
 * of the source system so the target system can receive the returned value.
 */
class ImpFlow: public Flow{
    protected:
        string name; /*!< Flow name */
        System* source; /*!< Source system */
        System* target; /*!< Target System */
    
    public:
        /**
         * @brief ImpFlow Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        ImpFlow();
        /** 
         * @brief ImpFlow Copy Constructor.
         * 
         * Following the Canonical Class Form 
         * @param copy make a copy of another flow
         */
        ImpFlow(ImpFlow &copy);
        /** 
         * @brief ImpFlow Constructor parameters of string, System and System.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name name of the flow
         * @param source input system of the flow
         * @param target output system of the flow
         */
        ImpFlow(string name, System* source, System* target);

        /** 
         * @brief Virtual ImpFlow Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~ImpFlow(){}

        /** 
         * @brief ImpFlow Get Name Method.
         * 
         * Returns the flow's name
         * @return string
         */
        string getName() const;
        /** 
         * @brief ImpFlow Get Source Method.
         * 
         * Returns the source system of the flow
         * @return System
         */
        System* getSource() const;
        /** 
         * @brief ImpFlow Get Target Method.
         * 
         * Returns the target system of the flow
         * @return System
         */
        System* getTarget()const;

        /** 
         * @brief ImpFlow Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to flow's name
         * @param name name of the flow
         */
        void setName(string name);
        /**
         * @brief ImpFlow Set Source System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's source
         * @param source input system of the flow
         */
        void setSource(System* source);
        /**
         * @brief ImpFlow Set Target System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's target
         * @param target output system of the flow
         */
        void setTarget(System* target);

        /** 
         * @brief ImpFlow Conect Method.
         * 
         * Receive two Systems as parameters and attributes it to flow's source and flowś target
         * @param source input system of the flow
         * @param target output system of the flow
         */
        void conect(System *, System *);

        /** 
         * @brief Virtual ImpFlow Execute Method.
         * 
         * This method will be implemented by class's children. It's responsible for 
         * return the value which the target system will receive considering the value that 
         * the source contains
         * @return double is going to be used to modify a value
         */
        virtual double execute() const = 0;

        /**
         * @brief ImpFlow Assignment operator.
         * 
         * Following the Canonical Class Form 
         * @param flow
         * @return ImpFlow& a copy of a flow
         */
        ImpFlow& operator=(ImpFlow &flow);
};

/** 
 * @brief Exponential Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Exponential: public ImpFlow{
    public:
        /**
         * @brief Exponential Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Exponential(string name, System *source, System *target);

        /**
         * @brief Exponential Destructor.
         * 
         */
        ~Exponential(){}
        
        /**
         * @brief Exponential Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

/** 
 * @brief Logistical Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Logistical: public ImpFlow{
    public:
        /**
         * @brief Logistical Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Logistical(string name, System *source, System *target);

        /**
         * @brief Logistical Destructor.
         * 
         */
        ~Logistical(){}
        
        /**
         * @brief Logistical Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

/** 
 * @brief Complex Class.
 * 
 * It's one of Flow's children. It overrides the execute method so the value of the Target
 * System can be modified and the dynamics works.
 */
class Complex: public ImpFlow{
    public:
        /**
         * @brief Complex Constructor parameters of string, System and System
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name 
         * @param source 
         * @param target
         */
        Complex(string name, System *source, System *target);

        /**
         * @brief Complex Destructor.
         * 
         */
        ~Complex(){}
        
        /**
         * @brief Complex Overriding Execute Method.
         * 
         * @return double 
         */
        double execute() const;
};

#endif