#include "Object.hpp"

Object::Object(const std::string& name)
{
	mName = name;
}

Object::~Object()
{
	;
}

Object* Object::copy(bool deep)
{
	(void)deep;
	Object *obj = new Object( mName );
	return obj;
}
