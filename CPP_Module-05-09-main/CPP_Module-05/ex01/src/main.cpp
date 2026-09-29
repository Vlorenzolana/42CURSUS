/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:01:00 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 18:04:34 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat junior("Junior", 145);
        Bureaucrat senior("Senior", 52);
        Bureaucrat boss("Boss", 1);

        Form    formA4("FormA4", 50, 150);
        std::cout << formA4 << std::endl;

        junior.signForm(formA4);
        senior.signForm(formA4);
        boss.signForm(formA4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}