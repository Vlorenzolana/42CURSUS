#include <unistd.h>

/* void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
} */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
#include <stdio.h>

/* int	main(void)
{
	unsigned char octet = 22;
	printf("Original bit");
	print_bits(octet);
	sleep(1);
	octet = swap_bits(octet);
	printf("Reversed bit");
	print_bits(octet);
	sleep(1);
	return (0);
} */