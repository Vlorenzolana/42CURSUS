/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:24:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:24:26 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

//	Use a helper template function to test iteration.
template <typename T>
void	iterate_and_print(MutantStack<T>& to_test)
{
	typename MutantStack<T>::container_type::iterator start;
	typename MutantStack<T>::container_type::iterator end;
	
	start = to_test.begin(); 
	end = to_test.end();
	while (start != end)
	{
		std::cout << *start << " ";
		start++;
	}
	std::cout << std::endl;
	return ;	
}

//	Use a helper template function to test is a std::stack<T> is empty. If not, measure size.
//	empty() and size() are inherited methods from std::stack
template <typename T>
void	test_contents(const MutantStack<T>& to_test)
{
	if (to_test.empty())
		std::cout << "Stack is empty" << std::endl;
	else
		std::cout << "Stack currently holds " << to_test.size() << " elements" << std::endl;
}

int	main()
{
	MutantStack<int>			int_stack;
	MutantStack<char>			char_stack;
	MutantStack<float>			float_stack;
	MutantStack<std::string>	string_stack;
	int							i = 0;

	std::cout << std::endl << "--- Testing INT stack ---" << std::endl;
	test_contents(int_stack);
	std::cout << "Pushing some elements into stack..." << std::endl;
	while (i < 10)
		int_stack.push(i++);
	test_contents(int_stack);
	std::cout << "Element on top is: " << int_stack.top() << std::endl;
	std::cout << "Iterating stack.." << std::endl;
	iterate_and_print(int_stack);
	std::cout << "Popping out an element... " << std::endl;
	int_stack.pop();
	test_contents(int_stack);
	std::cout << "Element on top is: " << int_stack.top() << std::endl;
	std::cout << "Emptying stack... " << std::endl;
	while (!int_stack.empty())
		int_stack.pop();
	test_contents(int_stack);
	
	std::cout << std::endl << "--- Testing CHAR stack ---" << std::endl;
    test_contents(char_stack);
    std::cout << "Pushing some elements into stack..." << std::endl;
    char_stack.push('A');
    char_stack.push('B');
    char_stack.push('C');
    test_contents(char_stack);
    std::cout << "Element on top is: " << char_stack.top() << std::endl;
	std::cout << "Iterating stack.." << std::endl;
	iterate_and_print(char_stack);
    std::cout << "Popping out an element... " << std::endl;
    char_stack.pop();
    test_contents(char_stack);
    std::cout << "Element on top is: " << char_stack.top() << std::endl;
    std::cout << "Emptying stack... " << std::endl;
    while (!char_stack.empty())
        char_stack.pop();
    test_contents(char_stack);

    std::cout << std::endl << "--- Testing FLOAT stack ---" << std::endl;
    test_contents(float_stack);
    std::cout << "Pushing some elements into stack..." << std::endl;
	i = 0;
	while (i < 10)
	{
		float_stack.push(i * 0.7142847);
		i++;
	}
    test_contents(float_stack);
    std::cout << "Element on top is: " << float_stack.top() << std::endl;
    std::cout << "Popping out an element... " << std::endl;
    float_stack.pop();
    test_contents(float_stack);
    std::cout << "Element on top is: " << float_stack.top() << std::endl;
	std::cout << "Iterating stack.." << std::endl;
	iterate_and_print(float_stack);
    std::cout << "Emptying stack... " << std::endl;
    while (!float_stack.empty())
        float_stack.pop();
    test_contents(float_stack);

    std::cout << std::endl << "--- Testing STRING stack ---" << std::endl;
    test_contents(string_stack);
    std::cout << "Pushing some elements into stack..." << std::endl;
    string_stack.push("EVERYBODY");
    string_stack.push("HATES");
    string_stack.push("C++");
    test_contents(string_stack);
    std::cout << "Element on top is: " << string_stack.top() << std::endl;
	std::cout << "Iterating stack.." << std::endl;
	iterate_and_print(string_stack);
    std::cout << "Popping out an element... " << std::endl;
    string_stack.pop();
    test_contents(string_stack);
    std::cout << "Element on top is: " << string_stack.top() << std::endl;
    std::cout << "Emptying stack... " << std::endl;
    while (!string_stack.empty())
        string_stack.pop();
    test_contents(string_stack);
	
	return 0;
	
}
