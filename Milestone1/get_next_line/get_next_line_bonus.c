/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:17:34 by masacco           #+#    #+#             */
/*   Updated: 2026/02/09 14:47:57 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_read(int fd, char **str, char *buffer)
{
	char	*temp;
	int		byte_read;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read < 0 || buffer == NULL)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	if (byte_read == 0)
		return (byte_read);
	temp = ft_strjoin(*str, buffer);
	free(*str);
	*str = temp;
	return (byte_read);
}

void	del_str1(char **str, char *temp, int i)
{
	temp[i] = '\0';
	free(*str);
	*str = temp;
	if (**str == 0)
	{
		free(*str);
		*str = NULL;
	}
}

static void	del_str(char **str)
{
	char	*temp;
	int		i;
	size_t	j;

	if (ft_strchr(*str, '\n') == NULL)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	temp = malloc(ft_strlen(ft_strchr(*str, '\n')));
	if (!temp)
		return ;
	i = 0;
	j = ft_strlen(*str) - ft_strlen(ft_strchr(*str, '\n')) + 1;
	while (j < ft_strlen(*str))
	{
		temp[i] = (*str)[j];
		i++;
		j++;
	}
	del_str1(str, temp, i);
}

static void	str_result(char **str, char **res)
{
	char	*diff;
	int		len;
	int		i;

	diff = ft_strchr(*str, '\n');
	len = ft_strlen(*str) - ft_strlen(diff) + 2;
	*res = malloc(len);
	if (!res)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*res)[i] = (*str)[i];
		i++;
	}
	(*res)[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char		*str[4096];
	char			*str_buffer;
	char			*str_res;
	int				byte_read;

	byte_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_buffer = malloc(BUFFER_SIZE + 1);
	if (!str_buffer)
		return (NULL);
	while (ft_strchr(str[fd], '\n') == NULL && byte_read > 0)
		byte_read = ft_read(fd, &str[fd], str_buffer);
	free (str_buffer);
	if (byte_read == -1)
		return (NULL);
	if (ft_strlen(str[fd]) == 0)
		return (NULL);
	str_result(&str[fd], &str_res);
	del_str(&str[fd]);
	return (str_res);
}

/*int main()
{
 	char *line;
 	char *line1;
 	char *line2;
	char *line3;
	
 	int	fd = open("text.txt", O_RDONLY);
 	line = get_next_line(fd);
 	printf("%d\n", fd);
 	printf("%s", line);
 	free (line);
	
 	int	fd1 = open("text1.txt", O_RDONLY);
 	line1 = get_next_line(fd1);
 	printf("%d\n", fd1);
 	printf("%s", line1);
 	free (line1);
	
 	int	fd2 = open("text2.txt", O_RDONLY);
 	line2 = get_next_line(fd2);
 	printf("%d\n", fd2);
 	printf("%s", line2);
 	free (line2);

	int	fd3 = open("text3.txt", O_RDONLY);
 	line3 = get_next_line(fd3);
 	printf("%d\n", fd3);
 	printf("%s", line3);
 	free (line3);
	
 	line = get_next_line(fd);
 	printf("%d\n", fd);
 	printf("%s", line);
 	free (line);
	
 	line1 = get_next_line(fd1);
 	printf("%d\n", fd1);
 	printf("%s", line1);
 	free (line1);
	
 	line2 = get_next_line(fd2);
 	printf("%d\n", fd2);
 	printf("%s", line2);
 	free (line2);

	line3 = get_next_line(fd3);
 	printf("%d\n", fd3);
 	printf("%s", line3);
 	free (line3);
	
 	close (fd);
 	close (fd1);
 	close (fd2);
	close (fd3);
 	return (0);
}*/