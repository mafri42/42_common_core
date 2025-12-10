/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:44:13 by masacco           #+#    #+#             */
/*   Updated: 2025/12/03 13:23:16 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	len;
	size_t	flag;

	len = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			len++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (len);
}

static void	ft_freearr(char **words, size_t i)
{
	if (words)
	{
		while (i > 0)
		{
			i--;
			free(words[i]);
		}
		free(words);
	}
}

static void	sub_str(char **words, char const *s, char c, size_t n_words)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*s && i < n_words)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s != c && *s)
			s++;
		if (s > start)
			words[i] = ft_substr(start, 0, s - start);
		if (!words[i])
		{
			ft_freearr(words, i);
			return ;
		}
		i++;
	}
	words[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	sub_str(str, s, c, count_words(s, c));
	if (!str[0] && count_words(s, c) > 0)
		return (NULL);
	return (str);
}

/* int main()
{
    char **res;
    char    *str1 = "helloxhellox";
    size_t i;

    i = 0;
    res = ft_split(str1, 'x');
    if (res)
    {
        while(res[i])
        {
            printf("%s\n", res[i]);
            free(res[i]);
            i++;
        }
        free(res);
    }
    return (0);
} */