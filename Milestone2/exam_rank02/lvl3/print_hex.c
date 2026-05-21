/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$*/

#include <unistd.h>

int ft_atoi(char *str)
{
    int sign;
    int res;
    int i;

    res = 0;
    sign = 1;
    i = 0;
    while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
        {
            sign = sign * -1;
            i++;
        }
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res * sign);
}

void    print_hex(int n)
{
    char    *hex_digits;

    hex_digits = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    n = hex_digits[n % 16];
    write(1, &n, 1);
}

int main(int argc, char **argv)
{
    int n;
    if (argc == 2)
    {
        n = ft_atoi(argv[1]);
        print_hex(n);
        write(1, "\n", 1);
        return (0);
    }
    write(1, "\n", 1);
    return (0);
}