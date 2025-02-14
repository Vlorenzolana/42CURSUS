#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (i-- > 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
    int i = 8;
    res = 0;
    while (i-- > 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
    }
    return (res);
}
#include <stdio.h>

int	main(void)
{
	unsigned char octet = 5;
	print_bits(octet);
    printf("\n");
    octet = reverse_bits(octet);
    print_bits(octet);
	return (0);
}