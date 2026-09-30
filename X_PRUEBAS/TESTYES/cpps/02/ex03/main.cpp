/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:56:59 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:34:32 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main() {
    // Define triangle vertices
    Point A(0, 0);
    Point B(100, 0);
    Point C(0, 100);

    // Define test points
Point points[] = {
    Point(49, 50),    // Justo dentro del triángulo, cerca de la hipotenusa
    Point(50, 50),    // Justo en la hipotenusa
    Point(51, 50),    // Apenas fuera del triángulo, cerca de la hipotenusa
    Point(75, 25),    // Dentro del triángulo, pero cerca de la hipotenusa
    Point(76, 25),    // Fuera del triángulo, justo al otro lado de la hipotenusa
    Point(99, 1),     // Cerca del extremo de la hipotenusa en B
    Point(1, 99),     // Cerca del extremo de la hipotenusa en C
    Point(50, 49),    // Apenas dentro, cerca de la hipotenusa
    Point(50, 51),    // Apenas fuera, sobre la hipotenusa
};

    // Test each point
    for (int i = 0; i < 9; ++i) {
        Point &P = points[i];
        if (bsp(A, B, C, P)) {
            std::cout << "Point (" << P.getX() << ", " << P.getY() << ") is inside the triangle.\n";
        } else {
            std::cout << "Point (" << P.getX() << ", " << P.getY() << ") is outside the triangle.\n";
        }
    }

    return 0;
}