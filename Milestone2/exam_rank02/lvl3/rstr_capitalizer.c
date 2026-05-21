/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>*/

#include <unistd.h>

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

int is_space(char c)
{
    if (((c >= 9) && (c <= 32)) || (c == 32))
        return (1);
    return (0);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_space(str[i + 1]) || (str[i + 1] == '\0'))
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
        while (i < argc)
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