/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:10:01 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:39:08 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():x(Fixed(0)),y(Fixed(0)){}

Point::Point(const float one, const float two):x(Fixed(one)),y(Fixed(two)){}

Point::Point(const Point& other): x(Fixed(other.x)), y(Fixed(other.y)){}

Point::~Point(){}

Point&	Point::operator = (const Point &model)
{
	this->~Point();
	new(this) Point(model.x.toFloat(), model.y.toFloat());
	return (*this);
}

Fixed	Point::getX()
{
	Fixed	a;
	a.setRawBits(x.getRawBits());
	return (a);
}
Fixed	Point::getY()
{
	Fixed	a;
	a.setRawBits(y.getRawBits());
	return (a);
}
