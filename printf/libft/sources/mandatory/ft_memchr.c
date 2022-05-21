/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:54:57 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/26 14:23:34 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*s_str;
	const unsigned char	*result;

	uc = c;
	s_str = s;
	result = NULL;
	while (!result && n--)
	{
		if (*s_str == uc)
			result = s_str;
		else
			s_str++;
	}
	return ((void *)result);
}
