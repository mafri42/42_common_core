/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int *res;
    int i;
    int len;

    i = 0;
    len = abs(start - end + 1);
    res = (int *)malloc(len);
    while (i < len)
    {
        if (start <= end)
            res[i++] = start++;
        else if (start >= end)
            res[i++] = start--;
    }
    return(res);
}


int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%ls", ft_range(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
	return(0);
}