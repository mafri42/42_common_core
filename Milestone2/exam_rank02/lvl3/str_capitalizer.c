/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>*/

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_space(char c)
{
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return (1);
    return (0);
}

char ft_to_upper(char c)
{
    if ((c >= 'a') && (c <= 'z'))
        c -= 32;
    return (c);
}

char ft_to_lower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        c += 32;
    return (c);
}

void    capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((i == 0) || (is_space(str[i - 1])))
            str[i] = ft_to_upper(str[i]);
        else
            str[i] = ft_to_lower(str[i]);
        ft_putchar(str[i++]);
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc >= 1)
    {
        i = 1;
        while (argv[i])
        {
            capitalizer(argv[i]);
            ft_putchar('\n');
            i++;
        }
        return (0);
    }
    ft_putchar('\n');
    return (0);
}