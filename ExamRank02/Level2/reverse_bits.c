#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	res = 0;
	i = 8;
	while (i-- > 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return (res);
}

int	main(void)
{
	unsigned char	octet;

	octet = 5;
	print_binary(octet);
	octet = reverse_bits(octet);
	print_binary(octet);
	return (0);
}
