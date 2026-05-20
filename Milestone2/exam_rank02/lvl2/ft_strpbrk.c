/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    if (!s1 || !s2)
        return (0);
    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int	main(void)
{
	char	*str1 = "Hellowordl!";
	char	*search = "o";
	char	*str2 = strpbrk(str1, search);
	char	*str3 = ft_strpbrk(str1, search);

	printf("ORIGINAL: %s\n", str2);
	printf("MY FUNCTION: %s\n", str3);

	return (0);
}