/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42istanbul.com.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:08 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/10 05:54:17 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}
char	*min_int(void)
{
	char	*min_int;

	min_int = (char *)malloc(sizeof(char) * 12); 
	if (!min_int)
		return (NULL);
	ft_strlcpy(min_int, "-2147483648", 12);
	return (min_int);
}
char	*ft_itoa(int n)
{
	char			*s;
	long int		len;
	unsigned int	number;
	
	if (n == -2147483648)
		return (min_int());
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		s[0] = '-';
	}
		else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}
