#include "Image.hpp"
#include "stb/stb_image.hpp"

#include <cassert>

/********************
 * class Image
 ********************/
Image::Image()
	: Object("image")
    , mWidth(0)
    , mHeight(0)
    , mChannels(0)
    , mType(Texel_Invalid)
{
    ;
}

Image::Image(int width, int height, int channels, TexelType type,
                         const unsigned char *data)
	: Object("image")
    , mWidth(width)
    , mHeight(height)
    , mChannels(channels)
    , mType(type)
{
    //Debug("width=%d height=%d channels=%d type=%d data=%p.", width, height,
    //      channels, type, data);

    resize(width, height, channels, type, data);
}

Image::~Image()
{
    ;
}

void Image::resize(int width, int height, int channels, TexelType type,
                         const unsigned char *data)
{
    //Debug("width=%d height=%d channels=%d type=%d data=%p.", width, height,
    //      channels, type, data);

    assert(width > 0 && height > 0 && channels > 0 && data && type != Image::Texel_Invalid);
    mWidth = width;
    mHeight = height;
    mChannels = channels;
    mType = type;

    // clear existing data
    mData.clear();

    // compute texel width in bytes
    size_t texelWidth = (int)type;
    mData.insert(mData.begin(), data,
                 data + (width * height * channels * texelWidth));
}

int Image::getWidth() const
{
    return mWidth;
}

int Image::getHeight() const
{
    return mHeight;
}

int Image::getChannels() const
{
    return mChannels;
}

Image::TexelType Image::getType() const
{
    return mType;
}

unsigned char *Image::getData()
{
    return &mData[0];
}

const unsigned char *Image::getData() const
{
    return &mData[0];
}

unsigned char *Image::operator[](const unsigned int &index)
{
    // compute texel width in bytes
    const size_t texelWidth = (size_t)mType;
    return &mData[index * texelWidth * mChannels];
}

unsigned char *Image::operator()(const unsigned int &x,
                                       const unsigned int &y)
{
    // compute texel width in bytes
    const size_t texelWidth = (size_t)mType;
    return &(mData[texelWidth * (y * mWidth * mChannels + x)]);
}

void Image::flipImageVertical()
{
    // compute texel width in bytes
    const size_t texelWidth = (size_t)mType;
    const size_t lineWidth = texelWidth * mChannels * mWidth;
    std::vector<unsigned char> scanline;
    scanline.resize(lineWidth);
    for (int ii = 0; ii <= mHeight / 2; ++ii)
    {
        unsigned char *ptr_to = &mData[ii * lineWidth];
        unsigned char *ptr_from = &mData[(mHeight - 1 - ii) * lineWidth];
        scanline.assign(ptr_to, ptr_to + lineWidth);
        memcpy(ptr_to, ptr_from, lineWidth);
        memcpy(ptr_from, &scanline[0], lineWidth);
    }
}
