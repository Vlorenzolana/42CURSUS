/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:19:50 by kabasolo          #+#    #+#             */
/*   Updated: 2025/05/13 12:34:44 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm> // std::find
#include <vector>    // std::vector

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	
	if (it == container.end())
		throw std::runtime_error("Value not found");
	
	return (it);
}
