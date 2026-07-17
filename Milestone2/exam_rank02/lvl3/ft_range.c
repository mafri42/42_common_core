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
#include <unistd.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int len = 0;
    int i = 0;
    int *range;

    if (start < end)
    {
        len = end - start + 1;
        range = malloc(len);
        while(start <= end)
        {
            range[i] = start;
            i++;
            start++;
        }        
    }
    else
    {
        len = start - end + 1;
        range = malloc(len);
        while(start >= end)
        {
            range[i] = start;
            i++;
            start--;
        }        
    }
    return(range);
}

int main(int ac, char **av)
{
    int *range = ft_range(0, -3);

    printf("%d, %d, %d, %d\n", range[0], range[1], range[2], range[3]);
}