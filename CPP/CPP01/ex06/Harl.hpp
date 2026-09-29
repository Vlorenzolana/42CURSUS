/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:47:42 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/30 19:04:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define HARL_HPP

# include <iostream>

class	Harl
{
	private:

		void	debug(void);
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

		typedef void (Harl::*method_pointer)(void);

	public:

		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};
