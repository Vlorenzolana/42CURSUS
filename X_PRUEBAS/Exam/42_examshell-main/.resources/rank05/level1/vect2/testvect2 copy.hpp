#ifndef TESTVECT2_HPP
#define TESTVECT2_HPP

#include <iostream>

class vect2
{
    int x, y;

    public:

        vect2() : x(), y()                          {}
        vect2(int x, int y) : x(x), y(y)            {}
        vect2(const vect2& o) : x(o.x), y(o.y)      {}

        vect2&  operator=(const vect2& o)           { x = o.x; y = o.y; return *this; }
        vect2   operator+(const vect2& o) const     { return vect2(x + o.x, y + o.y); }
        vect2&  operator+=(const vect2& o)          { x += o.x; y += o.y; return *this; }
        
        vect2   operator-(const vect2& o) const     { }
    };
    
#endif