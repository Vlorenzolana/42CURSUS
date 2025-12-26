/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:47:20 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:35:50 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define HARL_HPP

# include <iostream>

class	Harl
{
	private:

		void	debug(void);	//	Note that these return void and take (void) arguments.
		void	info(void);
		void	warning(void);
		void	error(void);

		enum complaintType
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN,
		};

		complaintType getComplaintLevel(std::string level);

		typedef void (Harl::*method_pointer)(void);		//	Pointer to member function.
		//	typedef:			Define a new type...
		//	void:				that returns void...
		//	(Harl::				belonging to class Harl...
		//	*					being a pointer to a member function...
		//	method_pointer)		aliased "method_pointer"...
		// (void)				that takes no arguments.

	public:

		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};
