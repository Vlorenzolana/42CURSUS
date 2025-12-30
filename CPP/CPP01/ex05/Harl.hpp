/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:46:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/30 16:52:42 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <array>
# include <string>

class	Harl
{
    private:

        void	debug(void) const;
        void	info(void) const;
        void	warning(void) const;
        void	error(void) const;

        enum complaintType
        {
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            UNKNOWN,
        };

        complaintType getComplaintLevel(std::string level);

        typedef void (Harl::*method_pointer)(void) const;

    public:

        Harl(void);
        ~Harl(void);

        void complain(const std::string& level);
};
