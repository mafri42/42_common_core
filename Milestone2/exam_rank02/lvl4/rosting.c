/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int word_start;
    int word_end;
    int printed;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    word_start = 0;
    word_end = 0;
    printed = 0;
    // Remove initial spacing
    while (argv[1][i] && is_space(argv[1][i]))
        i++;
    // Loop first word
    if (argv[1][i] && !is_space(argv[1][i]))
        word_start = i;
    while (argv[1][i] && !is_space(argv[1][i]))
        i++;
    word_end = i - 1;
    // Print the rest of the string
    while (argv[1][i])
    {
        while (argv[1][i] && is_space(argv[1][i]))
            i++;
        if (argv[1][i])
        {
            if (printed)
                write(1, " ", 1);
            while (argv[1][i] && !is_space(argv[1][i]))
                write(1, &argv[1][i++], 1);
            printed = 1;
        }
    }
    // Print the first word
    if (printed)
        write(1, " ", 1);
    while (word_start <= word_end)
        write(1, &argv[1][word_start++], 1);
    write(1, "\n", 1);
    return (0);
}
