/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int largest_n;

    i = 1;
    if (len == 0)
        return (0);
    largest_n = tab[0];
    while(i < len)
    {
        if (tab[i] > largest_n)
            largest_n = tab[i];
        i++;
    }
    return (largest_n);
}

#include <stdio.h>

int main(void)
{
    int myNumbers[] = {25, 0, 1000, 50, 75, 100};
    printf("%d\n", max(myNumbers, 3));
    return (0);
}