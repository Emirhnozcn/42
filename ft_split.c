/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozcan <eozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:13:54 by eozcan            #+#    #+#             */
/*   Updated: 2025/07/07 16:36:54 by eozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freearray(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int	ft_countword(const char *str, char c)
{
	int	i;
	int	sayac;

	i = 0;
	sayac = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			sayac++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (sayac);
}

char	*ft_putword(char *word, const char *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split_word(const char *s, char c, char **s2, int num_word)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_word)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (s2[word] == NULL)
			return (ft_freearray(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_word;

	if (s == NULL)
		return (0);
	num_word = ft_countword(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (s2 == NULL)
		return (0);
	s2 = ft_split_word(s, c, s2, num_word);
	return (s2);
}
