#include "Sprite.hpp"

Sprite::Sprite()
	: Node("sprite")
{
	
}

Sprite::~Sprite()
{
	
}

void Sprite::setTexture(RefPtr<Texture> texture)
{
	mTexture = texture;
}

void Sprite::setSource(const Rectangle& src)
{
	mSource = src;
}

void Sprite::setTarget(const Rectangle& dst)
{
	mTarget = dst;
}