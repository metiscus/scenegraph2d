#ifndef REFERENCED_HPP_
#define REFERENCED_HPP_

class Referenced
{
public:
	Referenced();
	
	inline unsigned int ref();
	inline unsigned int unref();
	
	virtual Referenced* copy(bool deep = false) = 0;

protected:
	// force creation on the stack
	virtual ~Referenced();
	
private:
	unsigned int mReferences;
	
	friend class RefPtr;
	
	// remove copy semantics
	Referenced(const Referenced&);
	Referenced& operator= (const Referenced&);
};

inline unsigned int Referenced::ref()
{
	return ++mReferences;
}

inline unsigned int Referenced::unref()
{
	return --mReferences;
}

#endif // REFERENCED_HPP_
