#include <stdio.h>
#include <unistd.h>

/*
Examples:

Example 1:
Input: 10 (Binary: 00001010)
Reversed Output: 01010000

Example 2:
Input: 5 (Binary: 00000101)
Reversed Output: 10100000

Example 3:
Input: 255 (Binary: 11111111)
Reversed Output: 11111111
*/

// Function that reverses the bits of a byte (unsigned char)
unsigned char	reverse_bits(unsigned char octet)
{
	int				index;
	unsigned char	result;

	result = 0;
	index = 8;
	while (index--)
	{
		// Store in result the reverse on the left and add the least significant bit of octet
		result = (result << 1) | (octet & 1);
		// Shift octet to the right to process the next bit
		octet >>= 1;
	}
	return (result);
}
/*
void	print_bits(unsigned char octet)
{
	int				index;
	unsigned char	bit;

	index = 8;
	while (index--)
	{
		bit = ((octet >> index) & 1) + '0';
		write(1, &bit, 1);
	}
}

// Main function

int	main(void)
{
	unsigned char value = 10; // Binary: 00001010
	unsigned char reversed = reverse_bits(value);

	print_bits(value); // Expected output: 00001010
	printf("\n");
	print_bits(reversed); // Expected output: 01010000
	printf("\n");

	value = 5; // Binary: 00000101
	reversed = reverse_bits(value);

	print_bits(value); // Expected output: 00000101
	printf("\n");
	print_bits(reversed); // Expected output: 10100000
	printf("\n");

	value = 255; // Binary: 11111111
	reversed = reverse_bits(value);

	print_bits(value); // Expected output: 11111111
	printf("\n");
	print_bits(reversed); // Expected output: 11111111
	printf("\n");

	return (0);
} */
/* 
Purpose of the Function :

	The function operates at the bit level on a single unsigned char(8 bits)
		.result stores the reversed bits as they are computed,
	and the output is the new unsigned char with the reversed bit order.

		2. Why Not a String
	?

	A string(or char *in C) represents a sequence of characters,
	which is a different concept entirely.Strings are not suitable for direct bitwise operations.The task is to reverse the bits of a single 8
		- bit value,
	not to represent it as text.

		3. Efficient Memory Use :

	Using an unsigned char ensures the function operates within the size of a single byte(8 bits),
	which is efficient in terms of memory and computation.Declaring result as a string would require allocating additional memory,
	which is unnecessary for this task.  */

	res = (res << 1) | (octet & 1) 
	octet >>= 1;

unsigned char bit / res bit = (octet >> i & 1) + '0';
write(1, &bit, 1);