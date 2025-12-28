/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:42:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:42:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"

Fixed	crossProduct(const Point& p1, const Point& p2, const Point& p3)
{
	Fixed Ax = p2.getX() - p1.getX();		//	Vector A: p2 - p1
	Fixed Ay = p2.getY() - p1.getY();
	Fixed Bx = p3.getX() - p1.getX();		//	Vector B: p3 - p1
	Fixed By = p3.getY() - p1.getY();

	return (Ax * By - Ay * Bx);				//	2D Cross Product (Ax * By - Ay * Bx)
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = crossProduct(a, b, point);	//	Calculate the "cross product" for each edge with respect to the test point P.
	Fixed d2 = crossProduct(b, c, point);	//	The sign of the result indicates which side of the line the point lies on.
	Fixed d3 = crossProduct(c, a, point);	//	If the point is inside the triangle, all three cross products must have the same sign.

	if (d1 == Fixed(0.0f) || d2 == Fixed(0.0f) || d3 == Fixed(0.0f))
        return (false);		// Point is on an edge or vertex and is considered to be OUTSIDE.

	bool has_neg = (d1 < Fixed(0.0f)) || (d2 < Fixed(0.0f)) || (d3 < Fixed(0.0f));	//	true if any are positive
	bool has_pos = (d1 > Fixed(0.0f)) || (d2 > Fixed(0.0f)) || (d3 > Fixed(0.0f));	//	true if any are negative

	return !(has_neg && has_pos);		//	If there's no mix of positive and negative values ,then the point is inside.
}

int	main(void)
{
	Point vertex_a(0, 0);
	Point vertex_b(10, 0);
	Point vertex_c(5, 7);
	Point to_check(3, 3);

	if(bsp(vertex_a, vertex_b, vertex_c, to_check))
		std::cout << "Point (" << to_check.getX() << "," << to_check.getY() << ") is INSIDE the triangle a-b-c" << std::endl;
	else
		std::cout << "Point (" << to_check.getX() << "," << to_check.getY() << ") is OUTSIDE the triangle a-b-c" << std::endl;
	return (0);
}