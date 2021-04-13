//  Devan Otton
//  CS 201
//  Color3.cpp
//  04.13.21

#include <iomanip>
#include "Color3.h"
#ifndef COLOR3_H
#define COLOR3_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::right;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <Windows.h>

class Color3
{
public:
    Color3();
    Color3(int R, int G, int B);

    // Returns 0.2126R + 0.7152G + 0.0722B
    int weightedSum() const;

    // Returns an ASCII char representing darkness
    // e.g. ' ' = WHITE and 'W' = BLACK
    char asciiValue() const;

    unsigned char r;
    unsigned char g;
    unsigned char b;
};

std::ostream& operator<<(std::ostream& ostr, const Color3& color);
std::istream& operator>>(std::istream& istr, Color3& color);

#endif
// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue)
{
    return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}
Color3::Color3()
    : r(0), g(0), b(0)
{ }
Color3::Color3(int R, int G, int B)
{
    r = (unsigned char)saturate(R, 255);
    g = (unsigned char)saturate(G, 255);
    b = (unsigned char)saturate(B, 255);
}
int Color3::weightedSum() const
{
    // Implement Y = 0.2126R + 0.7152G + 0.0722B
    // Ensure values are inside the range 0 to 255
    return saturate(0.2126 * r + 0.7152 * g + 0.0722 * b, 255);
}
char Color3::asciiValue() const
{
    // Use at least 16 characters, sort these from dark to light
    // or light to dark and then map the weightedSum() to the range
    // 0 to 15. Please pick your own characters
    const char values[] = "@#%DAKOIif:;'.-";
    unsigned darkness = 14 - (weightedSum() / 15) % 15;
    return values[darkness];
}
// Stream Operators for input and output
std::ostream& operator<<(std::ostream& ostr, const Color3& color)
{
    ostr << std::setw(3) << (int)color.r << " ";
    ostr << std::setw(3) << (int)color.g << " ";
    ostr << std::setw(3) << (int)color.b << " ";
    return ostr;
}
std::istream& operator>>(std::istream& istr, Color3& color)
{
    // Implement your own input for a Color3
    int r, g, b;
    istr >> r;
    istr >> g;
    istr >> b;

    color.r = saturate(r, 255);
    color.g = saturate(g, 255);
    color.b = saturate(b, 255);

    return istr;
}
