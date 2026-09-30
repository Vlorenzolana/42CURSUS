/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:24:55 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:39:20 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	
	public:
		Point();
		Point(const Point& other);
		Point(const float one, const float two);
		~Point();

		Point&	operator = (const Point& other);

		Fixed	getX();
		Fixed	getY();
};

bool	bsp(Point const a, Point const b, Point const c, Point const p);

#endif