/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:06:05 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/20 17:46:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>		// rand() and srand()
#include <ctime> 		// time()
#include <exception>	// For std::bad_cast

void identify(Base& p)
{
	std::cout << "Identifying through reference:	";
    try							//	When casting a reference, a failed dynamic_cast THROWS AN EXCEPTION
	{
        A& a_ref = dynamic_cast<A&>(p);
		(void)a_ref;
        std::cout << "Object is type A" << std::endl;
        return;
    }
	catch (const std::exception& e) {/*  Do nothing and fall through to the next check */}

    try
	{
        B& b_ref = dynamic_cast<B&>(p);
		(void)b_ref;
        std::cout << "Object is type B" << std::endl;
        return;
    }
	catch (const std::exception& e) {/* Do nothing and fall through to the next check */}

    try
	{
        C& c_ref = dynamic_cast<C&>(p);
		(void)c_ref;
        std::cout << "Object is type C" << std::endl;
        return;
    }
	catch (const std::exception& e)						// All casts failed: it's an unknown type
	{
        std::cout << "Object is unknown" << std::endl;
	}
}

void identify(Base *p)
{
    if (p == NULL)
	{
        std::cout << "Error: Pointer is NULL" << std::endl;
        return;
    }
	std::cout << "Identifying through pointer:	";

	if (dynamic_cast<A*>(p) != NULL)					// When casting a pointer, a failed dynamic_cast returns NULL
        std::cout << "Object is type A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Object is type B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Object is type C" << std::endl;
    else
        std::cout << "Object is unknown" << std::endl;	// All casts failed: it's an unknown type
}

Base* generate(void)
{
    int random_value = rand() % 3;

	switch (random_value)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));	// Seed the random number generator.

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Generating random object number " << (i + 1) << std::endl;
		Base *test = generate();
		identify(test);
		identify(*test);
		delete test;
		std::cout << std::endl;
	}
	std::cout << "Testing NULL pointer:" << std::endl;
	Base *wtest = NULL;
	identify(wtest);
	// Note: identify(*wtest) would dereference NULL → undefined behavior. Omitted on purpose.

	return 0;
}