#include <stdio.h>

void print_binary(unsigned char octet)
{
	int i = 8;
	while(i-- > 0)
		printf("%c", (octet >> i & 1) ? '1' : '0');
}
unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int main()
{
	unsigned char result = swap_bits(0b10110010);
	printf("Entrada: 10110010\n");
	printf("Salida:  ");
	print_binary(result);
	printf("\n");
	return(0);
}