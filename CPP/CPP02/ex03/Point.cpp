/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:42:28 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:42:30 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Point.hpp"

Point::Point() : _x(), _y()		//	Since members are 'const' they MUST be initialized before entering the constructor body.
{
	//	However the constructor body may be empty. Text added for testing.
	//std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x_coord, const float y_coord) : _x(x_coord), _y(y_coord)
{
	//std::cout << "Point custom float constructor called" << std::endl;
}

Point::Point(const Point& model) : _x(model._x), _y(model._y)
{
	//std::cout << "Point copy constructor called" << std::endl;	
}

Point::~Point()
{
	//std::cout << "Point destructor called" << std::endl;	
}	

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}