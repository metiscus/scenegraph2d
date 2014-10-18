#ifndef IMAGE_H_
#define IMAGE_H_

#include "Object.hpp"
#include <vector>
#include <cstdlib>
#include <cstring>

/**
    \brief Data used to create a Texture (usually used for data textures)
*/
class Image : public Object
{
public:
    enum TexelType {
        Texel_Invalid = 0,  //!< Invalid texel format
        Texel_U8 = 1,       //!< Unsigned byte 0-255
        Texel_F32 = 4       //!< 32 bit float
    };

    /// Creates an empty texture data object
    Image();

    /**
        \brief Creates a TextureData object and populates the fields
        \param width width in texels
        \param height height in texels
        \param channels number of color components for each texel (1=Grayscale, 2=Grayscale with Alpha, 3=RGB, 4=RGBA)
        \param data pointer to a buffer which contains at least width * height * channels * size of either unsigned byte or float depending on the type parameter
    */
    Image(int width, int height, int channels, TexelType type, const unsigned char* data);
    ~Image();

    /**
        \brief Resizes an existing TextureData object and populates the fields
        \param width width in texels
        \param height height in texels
        \param channels number of color components for each texel (1=Grayscale, 2=Grayscale with Alpha, 3=RGB, 4=RGBA)
        \param data pointer to a buffer which contains at least width * height * channels * size of either unsigned byte or float depending on the type parameter
    */
    void resize(int width, int height, int channels, TexelType type, const unsigned char* data);

    /// Returns the width in texels
    int getWidth() const;
    /// Returns the height in texels
    int getHeight() const;
    /// Returns the number of color components per texel
    int getChannels() const;
    /// Returns the texel type
    TexelType getType() const;

    /// Returns a raw pointer to the internal data
    unsigned char* getData();
    /// Returns a const pointer to the internal data
    const unsigned char* getData() const;
    /// Allows indexed operations on the internal data by texel
    unsigned char* operator[](const unsigned int& index);
    /**
        \brief Allows indexed operations on the internal data by texel
        \param x - texels in s direction
        \param y - texels in t direction
    */
    unsigned char* operator()(const unsigned int& x, const unsigned int& y);

    /// Some image formats require scanline inversion, this function inverts the scanlines
    void flipImageVertical();

private:
    int mWidth;                         //!< Width in texels
    int mHeight;                        //!< Height in texels
    int mChannels;                      //!< Color component count
    TexelType mType;                    //!< Type of each color component
    std::vector<unsigned char> mData;   //!< Raw data (protected with a std::vector)
};

#endif // IMAGE_H_
