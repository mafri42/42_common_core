/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stddef.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i])
    {
        j = 0;
        // Cerco se s[i] è dentro la stringa accept
        while (accept[j] && accept[j] != s[i])
            j++;
        
        // Se accept[j] è '\0', significa che ho scorso tutta la stringa 
        // accept e non ho mai trovato s[i]. Quindi s[i] non è permesso!
        if (accept[j] == '\0')
            return (i); // Mi fermo e restituisco quanti ne ho trovati finora
        
        i++;
    }
    return (i);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "aaabc";
	char	*accept = "b";

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