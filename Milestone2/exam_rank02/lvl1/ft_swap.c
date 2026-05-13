/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

void	ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

/*int	main(void)
{
	int	a = 1;
	int b = 2;

	ft_swap(&a, &b);

	printf("a is %d, b is %d", a, b);

	return (0);
}*/