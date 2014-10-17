#include <cassert>
#include "Referenced.hpp"

Referenced::Referenced()
{
	mReferences = 0;
}
	
Referenced::~Referenced()
{
	assert(mReferences == 0);
}
