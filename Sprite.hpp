#ifndef SPRITE_H_
#define SPRITE_H_

#include "Rectangle.hpp"
#include "RefPtr.hpp"
#include "Node.hpp"
#include "Texture.hpp"

class Sprite : public Node
{
public:
	Sprite();
	virtual ~Sprite();
	
	void setTexture(RefPtr<Texture> texture);
	void setSource(const Rectangle& src);
	void setTarget(const Rectangle& dst);
	
private:
	RefPtr<Texture> mTexture;
	Rectangle mSource;
	Rectangle mTarget;
};

#endif // SPRITE_H_