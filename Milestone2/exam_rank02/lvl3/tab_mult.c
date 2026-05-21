/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

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

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int main(int argc, char **argv)
{
    int i;
    int num;
    int res;

    if (argc != 2)
    {
        i = 1;
        num = ft_atoi(argv[1]);
        res = 0;
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            ft_putnbr(i * num);
            write(1, "\n", 1);
            i++;
        }
        return (0);
    }
    write(1, "\n", 1);
    return (0);
}