/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:12:39 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/07 16:36:50 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sc;
	size_t	dc;
	size_t	ds;
	size_t	ss;

	ss = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (ss);
	dc = ft_strlen(dst);
	ds = dc;
	if (size <= dc)
		return (size + ss);
	sc = 0;
	while (src[sc] && dc + 1 < size)
	{
		dst[dc] = src[sc];
		dc++;
		sc++;
	}
	dst[dc] = '\0';
	return (ds + ss);
}
