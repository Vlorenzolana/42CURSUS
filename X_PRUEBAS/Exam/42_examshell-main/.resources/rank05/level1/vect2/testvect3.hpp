#ifndef TESTVECT3_HPP
#define TESTVECT3_HPP

#include <iostream>

class vect3
{
    int x; y;

    public: 

        vect3() : x(), y() {}                                                           // constructor por defecto
        vect3(int x, int y ) : x(x), y(y) {}                                            // constructor por parametros
        vect3(const vect3& o) : x(o.x), y(o.y) {}                                       // constructor de copia. Crea un nuevo vect2 copiando x e y de otro objeto o

        vect3&  operator=(const vect3& o)        { x = o.x; y = o.y; return *this; }     // asigna x e y desde o y devuelve puntero (al vector)

        vect3   operator+(const vect3& o) const  { return vect3(x + o.x, y + o.y); }     // suma componente a componente del objeto y devuelve nuevo vector (nuevo valor)
        vect3&  operator+=(const vect3& o)       { x += o.x;  y += o.y; return *this; }  // suma en el propio componente del objeto y devuelve puntero
        vect3   operator-(const vect3& o) const  { return vect3(x - o.x, y - o.y); }     // resta componente a componente y devuelve el nuevo vector
        vect3&  operator-=(const vect3& o)       { x - o.x; y - o.y; return *this; }     // resta en el propio componte del objeto y develve puntero
        vect3   operator-()    const             { return vect3(-x, -y); }               // cambia el signo de ambas componentes

        vect3&  operator*(int s) const           { return vect3(x * s, y * s); }         // escala por s y devuelve nuevo vector
        vect3   operator*=(int s)                { x *= s, y *= s; return *this; }       //    
}