/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:51:54 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:48:20 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_split(char **split, size_t word_count)
{
	while (word_count)
		free(split[--word_count]);
	free(split);
	return (NULL);
}

static char	*ft_next_word(char const *s, char c, size_t *word_offset)
{
	size_t	result_len;
	char	*result;

	result = NULL;
	if (*s)
	{
		*word_offset = 0;
		while (s[*word_offset] == c)
			(*word_offset)++;
		s += *word_offset;
		result_len = 0;
		while (s[result_len] && s[result_len] != c)
			result_len++;
		if (result_len)
		{
			result = (char *)malloc(sizeof(char) * (result_len + 1));
			if (result)
			{
				ft_strlcpy(result, s, result_len + 1);
				*word_offset += result_len;
			}
		}
	}
	return (result);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		result += *s != 0;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_index;
	size_t	word_count;
	size_t	word_offset;
	char	**result;

	result = NULL;
	if (s)
	{
		word_count = ft_count_words(s, c);
		result = (char **)malloc(sizeof(char *) * (word_count + 1));
		if (result)
		{
			result[word_count] = NULL;
			word_index = -1;
			while (result && ++word_index < word_count)
			{
				result[word_index] = ft_next_word(s, c, &word_offset);
				if (!result[word_index])
					result = ft_free_split(result, word_index);
				else
					s += word_offset;
			}
		}
	}
	return (result);
}
