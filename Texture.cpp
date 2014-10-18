#include <GL/glew.h>
#include <GL/gl.h>

#include "Image.hpp"
#include "Texture.hpp"
#include "stb/stb_image.hpp"

/********************
 * class Texture
 ********************/
Texture::Texture()
	: Object("texture")
    , mIsDirty(false)
    , mGenerateMipmaps(true)
{
    glGenTextures(1, &mTexture);
}

Texture::~Texture()
{
    glDeleteTextures(1, &mTexture);
}

bool Texture::loadFromFile(const char *filename)
{
    if (!filename)
    {
        //Fatal("null filename.");
        return false;
    }

    int c, width, height;
    const GLubyte *loadedData = stbi_load(filename, &width, &height, &c, 4);
    if (loadedData != NULL)
    {
        mIsDirty = true;

        //Debug("loaded %s (%d x %d) with %d channels.", filename, width, height, c);
        //Debug("forcing RGBA.");

        // copy data to internal buffer and release
        mData->resize(width, height, 4, Image::Texel_U8, loadedData);
        stbi_image_free((void *)loadedData);

        // some file extensions require flipping
        std::string extension = filename;
        size_t itr = extension.rfind(".");
        if (itr != std::string::npos)
        {
            extension = extension.substr(itr + 1, extension.length() - itr);
            //Debug("file is of type %s.", extension.c_str());
            if (extension != "bmp")
            {
                // textureVFlip(mData->getData(), width, height);
                mData->flipImageVertical();
                //Debug("inverting scanlines.");
            }
        }

        glBindTexture(GL_TEXTURE_2D, 0);
    }
    else
    {
        //Error("Error loading %s. (%s).", filename, stbi_failure_reason());
        return false;
    }

    return true;
}

bool Texture::setFromData(RefPtr<Image> data)
{
    mIsDirty = true;
    mData = data;
    return true;
}

RefPtr<Image> Texture::getDataRW()
{
    mIsDirty = true; // automatically mark as dirty
    return mData;
}

const RefPtr<Image> Texture::getDataRO() const
{
    return mData;
}

void Texture::dirty()
{
    mIsDirty = true;
}

bool Texture::operator==(const Texture &rhs) const
{
    return mTexture == rhs.mTexture;
}

void Texture::setParameter(Texture::Parameter param, unsigned int value)
{
    GLenum glparam;

    switch (param)
    {
    case MinFilter:
        glparam = GL_TEXTURE_MIN_FILTER;
        break;
    case MagFilter:
        glparam = GL_TEXTURE_MAG_FILTER;
        break;
    case Wrap_S:
        glparam = GL_TEXTURE_WRAP_S;
        break;
    case Wrap_T:
        glparam = GL_TEXTURE_WRAP_T;
        break;
    default:
        return;
        break;
    }

    bind();
    glTexParameteriv(GL_TEXTURE_2D, glparam, (GLint *)&value);
}

int Texture::getWidth() const
{
    return mData->getWidth();
}

int Texture::getHeight() const
{
    return mData->getHeight();
}

unsigned int Texture::getObject()
{
    return mTexture;
}

void Texture::bind()
{
    _updateImageData();
    glBindTexture(GL_TEXTURE_2D, mTexture);
}

void Texture::enableGenerateMipmaps()
{
    mGenerateMipmaps = true;
}

void Texture::disableGenerateMipmaps()
{
    mGenerateMipmaps = false;
}

void Texture::_updateImageData()
{
    if (mIsDirty)
    {
        mIsDirty = false;
        // Debug("texture %d has dirty data, refreshing.", mTexture);
        //Info("texture %d has dirty data, refreshing.", mTexture);

        glBindTexture(GL_TEXTURE_2D, mTexture);

        GLenum texelType = GL_RGBA;

        switch (mData->getChannels())
        {
        case 1:
            texelType = GL_RED;
            break;
        case 2:
            texelType = GL_RG;
            break;
        case 3:
            texelType = GL_RGB;
            break;
        case 4:
            texelType = GL_RGBA;
            break;
        default:
        {
            //Warning("invalid channel count, ignoring data.");
            return;
            break;
        }
        }

        GLenum dataType;
        switch (mData->getType())
        {
        case Image::Texel_U8:
            dataType = GL_UNSIGNED_BYTE;
            break;
        case Image::Texel_F32:
            dataType = GL_FLOAT;
            break;

        case Image::Texel_Invalid: // intentional fall-through
        default:
        {
            //Warning("invalid channel size, ignoring data.");
            return;
            break;
        }
        }

        if (mData->getType() != Image::Texel_F32)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, texelType, mData->getWidth(),
                         mData->getHeight(), 0, texelType, dataType, mData->getData());
        }
        else
        {
            // support non-normalized textures
            // possible to use GL_RGBA32F as well if you need more resolution
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, mData->getWidth(),
                         mData->getHeight(), 0, texelType, dataType, mData->getData());
        }

        if (mGenerateMipmaps)
        {
            //Info("generating mipmaps.");
            glGenerateMipmap(GL_TEXTURE_2D);
        }
    }
}
