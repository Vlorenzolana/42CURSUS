
#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2& source);
		vect2& operator=(const vect2& source);

		int operator[](int index) const;
		int& operator[](int index); // NON-COST

		vect2 operator-() const;
		vect2 operator*(int num) const;

		vect2& operator*=(int num);

		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		vect2& operator*=(const vect2& obj);

		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		vect2 operator*(const vect2& obj) const;

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;

		~vect2();
};

vect2 operator*(int num, const vect2& obj);

std::ostream& operator<<(std::ostream& os,const vect2& obj);

#endif

