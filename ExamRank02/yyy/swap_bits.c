/* Subject
Assignment name : reverse_bits
Expected files : reverse_bits.c
Allowed functions
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the example)
and returns the result. Your function must be declared as follows :

	unsigned char reverse_bits(unsigned char octet);

Example :

	1 byte
	0010 0110
		||
		\/
	0110 0100
 */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;

    bit = (octet >> 4) | (4 << octet);
}

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while(i >= 0)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

int main(void)
{
    unsigned char tralala = 2;
    print_bits(tralala);
    return (0);
}
