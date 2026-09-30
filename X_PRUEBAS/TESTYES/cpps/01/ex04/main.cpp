/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:42:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/10 16:05:02 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: 3 arguments only." << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: First word can not be empty." << std::endl;
		return (1);
	}

	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open the file." << std::endl;
		return (1);
	}
	
	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open())
	{
        std::cerr << "Error: Could not create the output file." << std::endl;
		file.close();
        return (1);
    }
	
	std::ostringstream buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();
	
	std::size_t	pos = 0;
	std::size_t	prev = 0;
	while ((pos = content.find(s1, prev)) != std::string::npos)
	{
		output << content.substr(prev, pos - prev) << s2;
		prev = pos + s1.length();
	}
	output << content.substr(prev);
	
	file.close();
	output.close();
	return (0);
}
