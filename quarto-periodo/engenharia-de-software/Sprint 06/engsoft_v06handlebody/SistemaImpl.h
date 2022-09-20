#if ! defined(SYSTEM_IMPL_H)
#define SYSTEM_IMPL_H

#include "sistema.h"

#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int  numBodyDeleted;
#endif


class SystemBody{
public: 
    /// Constructor: zero references when the object is being built
	SystemBody(): refCount_ ( 0 ){  
#ifdef DEBUGING		
		numBodyCreated++;
#endif

    }

	/// Increases the number of references to this object
	void attach ()	{ refCount_++; }

	/// Decreases the number of references to this object.
	/// Destroy it if there are no more references to it
	void detach (){	
		if ( --refCount_ == 0 )	{ 
			delete this; 
#ifdef DEBUGING
			numBodyDeleted++; 
#endif
		}
	}

	/// Returns the number of references to this object
	int refCount(){ return refCount_; }

	/// Destructor
	virtual ~SystemBody(){}

private:

	/// No copy allowed
	SystemBody(const SystemBody&);

	/// Implementation
	SystemBody& operator=(const SystemBody&){return *this;}

	int refCount_; 	/// the number of references to this class

public:

    SystemBody(string n,double v):id_(n), value_(v), refCount_(0){ 
#ifdef DEBUGING		
		numBodyCreated++;
#endif
    
    };
    double getValue(void);
    virtual string getName(void);
    virtual void setValue(double);
    virtual void setName(string);

public:
    string id_;

protected:
    double value_;

};



class SystemHandle : public System
{

public:	

    /// Default constructor
    SystemHandle( ){  
		pImpl_ = new SystemBody(); 
        pImpl_->attach();  
#ifdef DEBUGING
		numHandleCreated++; //cout << "AQUI";
#endif	

	}
	/// constructor
	SystemHandle( string id ,double val){  
		pImpl_ = new SystemBody(id, val); 
        pImpl_->attach();  
#ifdef DEBUGING
		numHandleCreated++; //cout << numHandleCreated;
#endif	

	}
	
	/// Destructor
	virtual ~SystemHandle(){ pImpl_->detach(); 	
#ifdef DEBUGING
		numHandleDeleted++;
#endif

    }

	/// copy constructor 
	SystemHandle( const SystemHandle& hd ):pImpl_( hd.pImpl_ ) { 
                  pImpl_->attach();  
#ifdef DEBUGING
		numHandleCreated++;
#endif	

    }

	/// assignment operator
	SystemHandle& operator=( const SystemHandle& hd) {

		if (  this != &hd )
		{
			hd.pImpl_->attach();
			pImpl_->detach();	
			pImpl_  = hd.pImpl_;
		}
		return *this;
	}

protected:

	/// referência para a implementação
	SystemBody *pImpl_; 

public:

    double getValue(void){ return pImpl_->getValue();  } 
    virtual string getName(void){ return pImpl_->getName(); }
    virtual void setValue(double val ){ pImpl_->setValue(val); }
    virtual void setName(string id ){ pImpl_->setName( id ); }
	
};

#endif
