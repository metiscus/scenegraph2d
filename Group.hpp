#ifndef GROUP_H_
#define GROUP_H_

#include "Matrix.hpp"
#include "Node.hpp"
#include "RefPtr.hpp"
#include "Vector.hpp"

#include <vector>

class Group : public Node
{
public:
    Group(const char* name = "group");

	virtual inline Group* asGroup();
	virtual void computeBound() const;
    
    void addChild(RefPtr<Node> child);
    unsigned int getNumChildren() const;
    
    virtual void dirtyBound() const;
    const RefPtr<Node> getChildAtIndex(unsigned int idx) const;
    RefPtr<Node> getChildAtIndex(unsigned int idx);
    void removeChild(RefPtr<Node> child );
    void removeChildAtIndex(unsigned int idx);
    
protected:
    std::vector< RefPtr<Node> > mChildren;
};

inline Group* Group::asGroup()
{
    return this;
}

#endif // TRANSFORM_H_
