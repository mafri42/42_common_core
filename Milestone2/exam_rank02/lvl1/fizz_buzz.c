/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void ft_putnbr(int nb)
{
    char c;

    if (nb == -2147483648)
    {
        write (1, "-2147483648\n", 11);
        return ;
    }
    if (nb < 0)
    {
        write (1, "-", 1);
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr (nb / 10);
        ft_putnbr (nb % 10);
    }
    else
    {
        c = nb + '0';
        write (1, &c, 1);
    }
}

int main()
{
    int x = 1;

    while (x <= 100)
    {
        if (x % 3 == 0 && x % 5 == 0)
            write (1, "fizzbuzz", 8);
        else if (x % 3 == 0)
            write (1, "fizz", 4);
        else if (x % 5 == 0)
            write (1, "buzz", 4);
        else
            ft_putnbr(x);
        x++; 
        write (1, "\n", 1);
    }
}