/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:58:44 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 13:12:34 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float	crossProduct(Point a, Point b, Point p)
{
	Fixed	ABP((b.getX() - a.getX()) * (p.getY() - a.getY())
			  - (b.getY() - a.getY()) * (p.getX() - a.getX()));
	
	return (ABP.toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	bool cp1 = crossProduct(a, b, p) >= 0;
	bool cp2 = crossProduct(b, c, p) >= 0;
	bool cp3 = crossProduct(c, a, p) >= 0;
	
	return (cp1 == cp2 == cp3);
}
