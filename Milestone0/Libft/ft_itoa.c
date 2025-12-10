/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:17:44 by masacco           #+#    #+#             */
/*   Updated: 2025/12/06 18:10:57 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	long		num;
	const char	*digits;

	digits = "0123456789";
	num = n;
	len = num_len(num);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	else if (num == 0)
		res[0] = '0';
	while (num > 0)
	{
		res[--len] = digits[num % 10];
		num /= 10;
	}
	return (res);
}

/* int main()
{
    printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-1234));
    printf("%s\n", ft_itoa(0));
} */