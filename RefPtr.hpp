#ifndef REFPTR_HPP_
#define REFPTR_HPP_

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
RefPtr::RefPtr()
	: mRef(NULL)
{
	;
}

template<typename Base>
RefPtr::RefPtr(Base* rhs)
{
	if(rhs) {
		mRef = rhs;
		mRef->ref();
	}
}

template<typename Base>
RefPtr& RefPtr::operator=(const RefPtr& rhs)
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
RefPtr::~RefPtr()
{
	if(mRef && mRef->unref() == 0) { delete mRef; }
}

template<typename Base>
void RefPtr::reset(Base* ptr)
{
	Base *const old = mRef;
	mRef = ptr;
	old->ref();
	
	if(old->unref()==0) {
		delete old;
	}
}

template<typename Base>
bool RefPtr::isValid() const
{
	return mRef != NULL;
}

template<typename Base>
Base* RefPtr::get()
{
	return mRef;
}

template<typename Base>
Base* RefPtr::operator->()
{
	return mRef;
}

template<typename Base>
const Base* RefPtr::operator->() const
{
	return mRef;
}


#endif // REFPTR_HPP_
