/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:36:01 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/22 00:28:33 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*result;

	result = NULL;
	if (s1)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		end = ft_strlen(s1);
		if (end)
		{
			while (end && ft_strchr(set, s1[end]))
				end--;
			end++;
		}
		result = (char *)malloc(sizeof(char) * (end + 1));
		if (result)
		{
			result[end] = '\0';
			while (end--)
				result[end] = s1[end];
		}
	}
	return (result);
}
