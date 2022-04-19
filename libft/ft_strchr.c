/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:21 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/29 02:40:50 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			end;
	const char	*result;

	end = 0;
	result = NULL;
	while (!result && !end)
	{
		if (*s == (char)c)
			result = s;
		else
		{
			end = !*s;
			s += !end;
		}
	}
	return ((char *)result);
}
