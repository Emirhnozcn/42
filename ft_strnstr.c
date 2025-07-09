/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:17:11 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/09 17:03:53 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char*s1, const char*s2, size_t n)
{
	size_t	s2l;
	size_t	i;
	size_t	j;

	s2l = ft_strlen(s2);
	if (s1 == s2 || s2l == 0)
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& (i + j) < n && s1[i + j] == s2[j])
		{
			j++;
			if ((j == n && j == s2l) || j == s2l)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
