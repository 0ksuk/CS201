//  Devan Otton
//  CS 201
//  Image3.cpp
//  04.13.21

#include <iostream>
#include "Image3.h"
#include <string>
#include <sstream>
#include <fstream>
#ifndef IMAGE3_H
#define IMAGE3_CPP

#include <iostream>
#include <vector>
#include "Color3.h"

class Image3
{
public:
    Image3(unsigned width, unsigned height);

    const Color3& getPixel(unsigned x, unsigned y) const;
    void setPixel(unsigned x, unsigned y, const Color3& color);

    bool savePPM(const std::string& path) const;
    bool loadPPM(const std::string& path);

    void printASCII(std::ostream& ostr) const;

    std::vector<Color3> pixels;
    unsigned w;
    unsigned h;
    Color3 borderColor;
};

std::ostream& operator<<(std::ostream& ostr, const Image3& image);
std::istream& operator>>(std::istream& istr, Image3& image);

#endif
// Image3 Constructor
Image3::Image3(unsigned width, unsigned height)
{
    // TODO: resize the pixels array
    // TODO: initialize the internal w and h members
    w = width;
    h = height;

    pixels.resize(width * height);
}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const
{
    // TODO: Add error handling for unknown pixels
    // TERRIBLE OPTION 1: throw
    // BETTER OPTION 2: return a color
    // Hint: maybe this is already in the class?

    if (y * w + x > pixels.size()) {

        return pixels[0];
    }

    return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color)
{
    // TODO: Set the pixel to the new color
    pixels[y * w + x] = color;
}

bool Image3::savePPM(const std::string& path) const
{
    // TODO: Save the image to the disk
    // REQUIREMENT: Use the STREAM operators for the file contents
    std::ofstream fout(path);
    if (!fout) {
        return false;
    }
    fout << *this;
    fout.close();
    return false;
}

bool Image3::loadPPM(const std::string& path)
{
    // TODO: Load an image from the disk
    // REQUIREMENT: Use the STREAM operators for the file contents
    std::ifstream fin(path);
    if (!fin) {
        return false;
    }
    try {
        fin >> *this;
    }
    catch (...) {
        return false;
    }
    return true;
}

void Image3::printASCII(std::ostream& ostr) const
{
    // TODO: Print an ASCII version of this image

    for (std::size_t i = 0; i < pixels.size(); i++)
    {
        ostr << pixels[i].asciiValue();
        if (i != 0 && (i + 1) % w == 0)
        {
            ostr << '\n';
        }
    }
}

// STREAM OPERATORS for IMAGE3 class

std::ostream& operator<<(std::ostream& ostr, const Image3& image)
{
    // TODO: Write out PPM image format to stream
    // ASSUME FORMAT WILL BE GOOD
    ostr << "P3\n" << image.w << ' ' << image.h << "\n255";
    for (Color3 px : image.pixels)
    {
        ostr << '\n' << px;
    }
    return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image)
{
    // TODO: Read in PPM image format from stream
    // MAKE SURE FORMAT IS GOOD!!!
    std::string line;
    istr >> line;
    if (line != "P3") { // Tells us if the format is invalid
        throw;
    }
    image.pixels.clear(); // Empties the vector to put our new data in

    bool widthSet = false;
    bool heightSet = false;
    bool colorspaceSet = false;

    std::vector<int> rgb;

    while (true) {
        std::getline(istr, line);
        if (!istr) {
            break;
        }
        if (line[0] == '#' || line == "") continue;
        std::istringstream str(line);
        while (str)
        {
            int value;
            str >> value;
            if (!str) break;
            if (!widthSet)
            {
                widthSet = true;
                image.w = value;
                continue;
            }
            if (!heightSet)
            {
                heightSet = true;
                image.h = value;
                continue;
            }
            if (!colorspaceSet)
            {
                colorspaceSet = true;
                continue;
            }
            rgb.push_back(value);
            if (rgb.size() == 3)
            {
                image.pixels.push_back(Color3(rgb[0], rgb[1], rgb[2]));
                rgb.clear();
            }
        }
    }
    return istr;
}
