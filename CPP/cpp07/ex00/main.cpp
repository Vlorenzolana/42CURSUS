/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:59:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 18:32:32 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iomanip>
#include <limits>

// ORIGINAL MAIN (commented for reference)
int main( void )
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;
	return 0;
}

// EXTENDED TEST MAIN with floats and various types
/* int main( void )
{
	std::cout << "======== TEST 1: INT ========" << std::endl;
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 2: FLOAT ========" << std::endl;
	float x = 3.14f;
	float y = 2.71f;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 3: DOUBLE ========" << std::endl;
	double p = 42.123456;
	double q = 99.654321;
	std::cout << "Before swap: p = " << p << ", q = " << q << std::endl;
	::swap(p, q);
	std::cout << "After swap: p = " << p << ", q = " << q << std::endl;
	std::cout << "min(p, q) = " << ::min(p, q) << std::endl;
	std::cout << "max(p, q) = " << ::max(p, q) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 4: CHAR ========" << std::endl;
	char c1 = 'A';
	char c2 = 'Z';
	std::cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
	std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 5: STRING ========" << std::endl;
	std::string str1 = "chaine1";
	std::string str2 = "chaine2";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min(str1, str2) = " << ::min(str1, str2) << std::endl;
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 6: EQUAL VALUES ========" << std::endl;
	int e1 = 42;
	int e2 = 42;
	std::cout << "e1 = " << e1 << ", e2 = " << e2 << std::endl;
	std::cout << "min(e1, e2) = " << ::min(e1, e2) << std::endl;
	std::cout << "max(e1, e2) = " << ::max(e1, e2) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 7: NEGATIVE VALUES ========" << std::endl;
	int neg1 = -50;
	int neg2 = -10;
	std::cout << "Before swap: neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
	::swap(neg1, neg2);
	std::cout << "After swap: neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
	std::cout << "min(neg1, neg2) = " << ::min(neg1, neg2) << std::endl;
	std::cout << "max(neg1, neg2) = " << ::max(neg1, neg2) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 8: EXTREME FLOAT VALUES ========" << std::endl;
	float tiny = 0.0001f;
	float large = 1000000.5f;
	std::cout << std::scientific << std::setprecision(6);
	std::cout << "Before swap: tiny = " << tiny << ", large = " << large << std::endl;
	::swap(tiny, large);
	std::cout << "After swap: tiny = " << tiny << ", large = " << large << std::endl;
	std::cout << "min(tiny, large) = " << ::min(tiny, large) << std::endl;
	std::cout << "max(tiny, large) = " << ::max(tiny, large) << std::endl;
	std::cout << std::endl;

	std::cout << "======== TEST 9: MIXED SIGNS (FLOAT) ========" << std::endl;
	float neg_f = -3.5f;
	float pos_f = 2.5f;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Before swap: neg_f = " << neg_f << ", pos_f = " << pos_f << std::endl;
	::swap(neg_f, pos_f);
	std::cout << "After swap: neg_f = " << neg_f << ", pos_f = " << pos_f << std::endl;
	std::cout << "min(neg_f, pos_f) = " << ::min(neg_f, pos_f) << std::endl;
	std::cout << "max(neg_f, pos_f) = " << ::max(neg_f, pos_f) << std::endl;
	std::cout << std::endl;

	return 0;
} */