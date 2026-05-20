/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char res;
    int i;

    i = 8;
    res = 0;
    while (i-- > 0)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
    }
    return (res);
}

#include <stdio.h>

int	main(void)
{
	unsigned char	resultado;
	unsigned char	octet;

	octet = 0x42;
	resultado = reverse_bits(octet);
	printf("Octeto original: 0x%X\n", octet);
	printf("Octeto con bits intercambiados: 0x%X\n", resultado);
	return (0);
}
