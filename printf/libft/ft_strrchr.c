/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:50 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/29 02:41:43 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*s_end;
	char	*result;

	s_end = s + ft_strlen(s);
	result = NULL;
	while (!result && s_end >= s)
	{
		if (*s_end == (char)c)
			result = s_end;
		else
			s_end--;
	}
	return (result);
}
