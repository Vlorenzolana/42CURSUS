/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:21:25 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/28 19:30:33 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string MyToUpper(const std::string& str)
{
    std::string res;
    size_t i;
    i = 0;

    while (i < str.size())
    {
        // cast to avoid negative (ascii > 127, negatives), undefined behaviour
        unsigned char c = static_cast<unsigned char>(str[i]); 
        res += static_cast<char>(std::toupper(c));
        ++i;
    }
    return res;
}

int main(int argc, char** argv)
{
    int i;

    i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        while (i < argc)
        {
            std::cout << MyToUpper(argv[i]);
            i++;
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << '\n';
return 0;
}
