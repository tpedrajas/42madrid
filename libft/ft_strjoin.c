/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:18:42 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/27 00:11:18 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	result = NULL;
	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (result)
		{
			ft_strlcpy(result, s1, s1_len + 1);
			ft_strlcat(result, s2, s1_len + s2_len + 1);
		}
	}
	return (result);
}
