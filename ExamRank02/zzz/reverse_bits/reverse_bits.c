/*
 * Subject
 *
 * Assignment name  : reverse_bits
 * Expected files   : reverse_bits.c
 * Allowed functions:
 * --------------------------------------------------------------------------------
 *
 *  Write a function that takes a byte, reverses it, bit by bit (like the
 *  example) and returns the result.
 *
 *  Your function must be declared as follows:
 *
 *  unsigned char	reverse_bits(unsigned char octet);
 *
 *  Example:
 *
 *  1 byte
 *  _____________
 *
 * 0010  0110
 *  	||
 *  	\/
 * 0110  0100
 */

unsigned char       reverse_bits(unsigned char octet)
{
	unsigned char res;
 	int i;

	res = 0;
	i = 8;	
	while(i-- > 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return(res);
}

#include <unistd.h>
void print_bits(unsigned char octet)
{
	unsigned char bitly;
	int i = 8;

	while(i-- > 0)
	{
		bitly = (octet >> i & 1) + '0';
		write(1, &bitly, 1);
	}
}

int main(void)
{
	unsigned char binary = 38;
	print_bits(binary);
	binary = reverse_bits(binary);
	write(1, "\n", 1);
	print_bits(binary);
	return(0);
}
