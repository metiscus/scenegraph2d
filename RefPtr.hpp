#ifndef REFPTR_HPP_
#define REFPTR_HPP_

#ifndef NULL
#define NULL ((void*)0x0)
#endif

#include <cstdlib>

template<typename Base>
class RefPtr
{
public:
	RefPtr();
	RefPtr(const RefPtr& rhs);
	RefPtr(Base* rhs);
	
	RefPtr& operator=(const RefPtr& rhs);
	
	~RefPtr();
	
	void reset(Base* ptr);
	bool isValid() const;
	
	Base* get();
	
	Base* operator->();
	const Base* operator->() const;

private:
	Base *mRef;
};

template<typename Base>
RefPtr<Base>::RefPtr()
	: mRef(NULL)
{
	;
}

template<typename Base>
RefPtr<Base>::RefPtr(Base* rhs)
{
	if(rhs) {
		mRef = rhs;
		mRef->ref();
	}
}

template<typename Base>
RefPtr<Base>& RefPtr<Base>::operator=(const RefPtr& rhs)
{
	Base *const old = mRef;
	mRef = rhs.mRef;
	old->ref();
	
	if(old->unref()==0) {
		delete old;
	}
	return *this;
}

template<typename Base>
RefPtr<Base>::~RefPtr()
{
	if(mRef && mRef->unref() == 0) { delete mRef; }
}

template<typename Base>
void RefPtr<Base>::reset(Base* ptr)
{
	Base *const old = mRef;
	mRef = ptr;
	old->ref();
	
	if(old->unref()==0) {
		delete old;
	}
}

template<typename Base>
bool RefPtr<Base>::isValid() const
{
	return mRef != NULL;
}

template<typename Base>
Base* RefPtr<Base>::get()
{
	return mRef;
}

template<typename Base>
Base* RefPtr<Base>::operator->()
{
	return mRef;
}

template<typename Base>
const Base* RefPtr<Base>::operator->() const
{
	return mRef;
}


#endif // REFPTR_HPP_
