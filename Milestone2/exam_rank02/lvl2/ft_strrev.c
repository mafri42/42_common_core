/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

char    *ft_strrev(char *str)
{
    int len;
    int i;
    char temp;

    len = 0;
    while (str[len])
        len++;
    i = 0;
    len -= 1;
    while (len > i)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}
#include <stdio.h>

int main(void)
{
    char s[] = "Hello??";
    ft_strrev(s);
    printf("%s\n", s);
    return (0);
}