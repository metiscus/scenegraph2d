#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>

#include "Referenced.hpp"

class Object : public Referenced
{
public:
	Object(const std::string& name);
	
	virtual Object* copy(bool deep = false);
	
protected:
	virtual ~Object();

private:
	std::string mName;
	
};

#endif // OBJECT_HPP_
