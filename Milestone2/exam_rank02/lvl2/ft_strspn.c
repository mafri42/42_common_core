/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (s[i] && accept[j])
    {
        if (s[i] == accept[j])
        {
            j = 0;
            i++;
        }
        else
            j++;
    }
    return (i);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "aaabc";
	char	*accept = "a";

	printf("ORIGINAL: %ld\n", strspn(s, accept));
	printf("MY FUNCTION: %ld\n", ft_strspn(s, accept));

	return (0);
}

/*
Conta quanti caratteri iniziali di s appartengono a accept
s → stringa da controllare
accept → caratteri accettati
Restituisce un numero (size_t)
*/