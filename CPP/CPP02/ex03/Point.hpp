/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:42:32 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:42:35 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:

		const Fixed	_x;
		const Fixed	_y;

		Point&	operator=(const Point& other);		//	Points are constant. This implies that they are NOT ASSIGNABLE. "Point1 = Point2" implies changing Point1.
													//	Best practice in C++98: Make it private and provide no implementation (in C++11 we would "= delete").

	public:

		Point();											//	Default constructor.
		Point(const float x_coord, const float y_coord);	//	Custom float constructor.
		Point(const Point& model);							//	Copy constructor.
		~Point();											//	Destructor.

		Fixed	getX() const;								//	Getter methods.
		Fixed	getY() const;
};

