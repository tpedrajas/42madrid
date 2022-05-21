/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:34:14 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/27 17:31:56 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_remaining;
	char	*result;

	result = NULL;
	if (s)
	{
		s_remaining = ft_strlen(s);
		if (start < s_remaining)
			s_remaining -= start;
		else
		{
			start = s_remaining;
			s_remaining = 0;
		}
		if (s_remaining < len)
			len = s_remaining;
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (result)
			ft_strlcpy(result, s + start, len + 1);
	}
	return (result);
}
