/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>

int is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}
int count_words(char *str)
{
    int i = 0;
    int words = 0;

    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i])
        {
            words++;
            while (str[i] && !is_space(str[i]))
                i++;
        }
    }
    return (words);
}

int word_len(char *str, int i)
{
    int len = 0;
    while (str[i] && !is_space(str[i]))
    {
        len++;
        i++;
    }
    return (len);
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int len;
    char **res;

    res = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!res)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i])
        {
            len = word_len(str, i);
            res[j] = malloc(sizeof(char) * (len + 1));
            if (!res[j])
                return (NULL);
            k = 0;
            while (k < len)
                res[j][k++] = str[i++];
            res[j][k] = '\0';
            j++; 
        }
    }
    res[j] = NULL;
    return (res);
}

/*
#include <stdio.h>

int main(void)
{
    char *str = "Hello all of you!";
    printf("%s", str);
    int i = 0;
    char **res = ft_split(str);
    while (res[i])
    {
        printf("%s\n", res[i]);
        i++;
    }
    return (0);
}
*/