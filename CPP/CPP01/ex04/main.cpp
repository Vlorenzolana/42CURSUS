/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:44:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:29:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Must take exactly 3 args" << std::endl;
		std::cout << "Usage: ./sed <filename> <to_be_replaced> <to_replace_with>" << std::endl;
		return (1);
	}

	std::string	to_extract = argv[2];
	std::string	to_insert = argv[3];

	if (to_extract.empty())
	{
		std::cout << "Error: Cannot extract an empty string" << std::endl;
		return (1);
	}
	
	std::string inputFileName = argv[1];
	std::ifstream	inputfile(inputFileName.c_str());
	if (!inputfile.is_open())
	{
		std::cout << "Error: Cannot open " << inputFileName << std::endl;
		return (1);
	}

	std::string outputFileName = inputFileName + ".replace";
	std::ofstream	outputfile(outputFileName.c_str());
	if (!outputfile.is_open())
	{
		std::cout << "Error: Cannot open " << outputFileName << std::endl;
		inputfile.close();
		return (1);
	}

	std::string line;
	size_t		position;
	size_t		extract_len = to_extract.length();
	size_t		insert_len = to_insert.length();
    while (std::getline(inputfile, line))
    {
		position = 0;
		while ((position = line.find(to_extract, position)) != std::string::npos)
        {
            line.erase(position, extract_len);
            line.insert(position, to_insert);
            if (insert_len > 0)
                position += insert_len; 
            else
                position++; 
        }
        outputfile << line << std::endl;
    }
	inputfile.close();
	outputfile.close();	
		
	return (0);
}
