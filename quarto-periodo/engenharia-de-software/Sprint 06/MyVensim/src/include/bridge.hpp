/**
 * @file Bridge.h
 * @brief The classes Handle and Body implements "bridge" design pattern (also known as 
 *	"handle/body idiom").The class Body was implemented based on the class teCounted
 *	writed by Ricardo Cartaxo and Gilberto Câmara and founded in the geographic library TerraLib.
 * @author Prof. Tiago Garcia de Senna Carneiro - UFOP, MG, Brazil
 */
#if !defined(HANDLE_BODY)
#define HANDLE_BODY

#define DEBUGING
#ifdef DEBUGING
	extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int numBodyDeleted;
#endif

/** 
 * @brief
 *
 * The classes Handle and Body implements the "bridge" design pattern (also known as
 * "handle/body idiom").
 * 
 */
template <class T> 
class Handle
{
public:	

	/**
	 * @brief Construct a new Handle< T> object
	 * 
	 */
	Handle<T>( ){
		pImpl_ = new T; 
        pImpl_->attach();
		#ifdef DEBUGING
			numHandleCreated++;
		#endif
	}
	
	
    /**
     * @brief Destroy the Handle< T> object
     * 
     */
	virtual ~Handle<T>(){
		pImpl_->detach();

		#ifdef DEBUGING
			numHandleDeleted++;
		#endif
	}

    /**
     * @brief Construct a new Handle< T> object
     * 
     * copy constructor
     * @param hd 
     */
	Handle<T>( const Handle& hd ):pImpl_( hd.pImpl_ ) { pImpl_->attach();  }

    /**
     * @brief Assignment operator
     * 
     * @param hd 
     * @return Handle<T>& 
     */
	Handle<T>& operator=( const Handle& hd) {
		if ( this != &hd )
		{
			hd.pImpl_->attach();
			pImpl_->detach();	
			pImpl_ = hd.pImpl_;
		}
		return *this;
	}
protected:

	/// referência para a implementação
	T *pImpl_; 
};

/**
 * @brief
 * 
 * The class Implementation was implemented based on the class teCounted writed by Ricardo Cartaxo 
 * and Gilberto Câmara and founded in the geographic library TerraLib.
 */

class Body
{	
public:

    /**
     * @brief Construct a new Body object
     * 
     * Constructor: zero references when the object is being built
     */
	Body(): refCount_(0){
		numBodyCreated++;
	}

    /**
     * @brief 
     * 
     * Increases the number of references to this object
     */
	void attach ()	{ refCount_++; }

    /**
     * @brief 
     * 
     * Decreases the number of references to this object.
     * Destroy it if there are no more references to it
     */
	void detach (){	
		if ( --refCount_ == 0 )	{ 
			delete this;
		}
	}

	/**
	 * @brief 
	 * 
	 * @return int 
	 */
	int refCount(){ return refCount_; }

	/**
	 * @brief Destroy the Body object
	 * 
	 */
	virtual ~Body(){
		#ifdef DEBUGING
			numBodyDeleted++;
		#endif
	}

private:

    /**
     * @brief Construct a new Body object
     * 
     * No copy allowed
     * @param Body 
     */
	Body(const Body&);

	/**
	 * @brief Assignment operatoR
	 * 
	 * @return Body& 
	 */
	Body& operator=(const Body&){return *this;}

	int refCount_; 	/// the number of references to this class

};

#endif
