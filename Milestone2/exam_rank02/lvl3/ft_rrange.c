/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/


#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	*result;
	int		i;
	int		len;

	i = 0;
	len = abs(end - start + 1);
	result = (int *)malloc(len);
	while (i < len)
	{
		if (end <= start)
			result[i++] = end++;
		else if (end >= start)
			result[i++] = end--;
	}
	return(result);
}
 
int	main(int argc, char **argv)
{
	if (argc == 3)
		{	
		printf("%ls", ft_rrange(atoi(argv[1]), atoi(argv[2])));
		//free();
		}
	printf("\n");
	return(0);
}