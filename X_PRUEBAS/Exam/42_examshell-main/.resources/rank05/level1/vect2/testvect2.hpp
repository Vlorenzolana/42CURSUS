#ifndef TESTVECT2_HPP
#define TESTVECT2_HPP

#include <iostream>

class vect2
{
    int x, y;

    public:

        vect2() : x(), y() {}                               // Constructor por defecto. Inicializa x e y a 0 (int() => 0).
        vect2(int x, int y) : x(x), y(y) {}                 // Constructor con parámetros. Crea el vector con los valores que le pases, por ejemplo vect2 v(3, 5).
        vect2(const vect2& o) : x(o.x), y(o.y) {}           // Constructor de copia. Crea un nuevo vect2 copiando x e y de otro objeto o.

        vect2&  operator=(const vect2& o)                   { x = o.x; y = o.y; return *this; } // asigna x e y desde o y devuelve este objeto
        vect2   operator+(const vect2& o) const             { return vect2(x + o.x, y + o.y); } // suma componente a componente y devuelve nuevo vector
        vect2&  operator+=(const vect2& o)                  { x += o.x; y += o.y; return *this; } // suma en el propio objeto y devuelve referencia
        
        vect2   operator-(const vect2& o) const             { return vect2(x - o.x, y - o.y); } // resta componente a componente y devuelve nuevo vector
        vect2&  operator-=(const vect2& o)                  { x -= o.x; y -= o.y; return *this; } // resta en el propio objeto y devuelve referencia
        vect2   operator-()    const                        { return vect2(-x, -y); } // cambia el signo de ambas componentes

        vect2   operator*(int s) const                      { return vect2(x * s, y * s); } // escala por s y devuelve nuevo vector
        vect2&  operator*=(int s)                           { x *= s; y += s; return *this; } // escala x y suma s a y (ojo: normalmente sería y *= s)
        friend vect2  operator*(int s, const vect2& v)      { return v * s; }
        
        vect2&  operator++()                                { ++x; ++y; return *this; } // pre-incremento: incrementa y devuelve el actual
        vect2   operator++(int)                             { vect2 t(*this); ++(*this); return t;} // post-incremento: devuelve copia anterior
        vect2&  operator--()                                { --x; --y; return *this; } // pre-decremento: decrementa y devuelve el actual
        vect2   operator--(int)                             { vect2 t(*this); --(*this); return t;} // post-decremento: devuelve copia anterior

        bool   operator==(const vect2& o)  const            { return x == o.x && y == o.y; } // true si ambas componentes son iguales
        bool   operator!=(const vect2& o)  const            { return !(*this == o); } // true si son distintos

        int&   operator[](int i)                            { return i == 0 ? x : y; } // acceso por índice (0->x, otro->y), modificable
        const int&   operator[](int i) const                { return i == 0 ? x : y; } // acceso por índice en objeto const

        friend std::ostream& operator<<(std::ostream& os, const vect2& v)
        { return os << "{" << v.x << ", " << v.y << "}" << std::endl; } // imprime {x, y} y añade salto de línea
    };
    
#endif