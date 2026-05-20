/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>*/

#include <unistd.h>

int	is_word(char c)
{
	if ((c == 32) || ((c >= 9) && (c <= 13)))
		return (0);
	return (1);	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	space;
	int	printed;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	space = 0;
	printed = 0;
	while (argv[1][i])
	{
		while (is_word(argv[1][i]) == 0)
		{
			space = 1;
			i++;
		}
		if (!argv[1][i])
			break;
		if ((space == 1) && (printed == 1))
			write(1, " ", 1);
		space = 0;
		printed = 1;
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}