#include <unistd.h>

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
/* 
int	main(void)
{
	unsigned char octet;

	octet = 222;
	print_bits(octet);
	return (0);
} */
