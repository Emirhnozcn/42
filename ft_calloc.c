/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42istanbul.com.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:18:26 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/10 05:34:12 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;

	array = malloc(num * size);
	if (!array)
		return(NULL);
	ft_bzero(array, num * size);
	return (array);
}
