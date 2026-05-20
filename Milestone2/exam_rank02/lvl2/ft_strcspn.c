/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/


#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;		
		}
		i++;
	}
	return (i);
}

/*
The  strcspn()  function  calculates  the  length of the initial segment of s
which consists entirely of bytes not in reject.
This function returns the number of characters in the first string before the 1st occurrence
of character present in second string. */

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello!";
	char	str2[] = "!l";

	printf("Original strcspn: %ld\n", strcspn(str1, str2));
	printf("My strcspn: %ld\n", ft_strcspn(str1, str2));

	return (0);
}