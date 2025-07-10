/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42istanbul.com.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:12:06 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/10 05:02:09 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	slen;
	size_t	finish;

	finish = 0;
	if (s == NULL)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	s2 = (char *)malloc(sizeof(char) * (finish + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s + start, finish +1);
	return (s2);
}
