/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

unsigned char	swap_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
}

#include <stdio.h>
int	main(void)
{
	unsigned char	resultado;
	unsigned char	octet;

	octet = 0x53;
	resultado = swap_bits(octet);
	printf("Octeto original: 0x%X\n", octet);
	printf("Octeto con bits intercambiados: 0x%X\n", resultado);
	return (0);
}