/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:03 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/26 14:23:40 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;
	int					result;

	s1_str = s1;
	s2_str = s2;
	result = 0;
	while (!result && n--)
		result = *(s1_str++) - *(s2_str++);
	return (result);
}
