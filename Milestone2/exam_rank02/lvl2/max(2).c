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
    int big;

    i = 0;
    big = 0;
    if (len == 0)
        return (0);
    while(i < len)
    {
        if (tab[i] > big)
            big = tab[i];
        i++;
    }
    return (big);
}

#include <stdio.h>

int main(void)
{
    int myNumbers[] = {25, 0, 1000, 50, 75, 100};
    printf("%d\n", max(myNumbers, 3));
    return (0);
}