/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:40 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/26 22:45:58 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;
	int					result;

	s1_str = (const unsigned char *)s1;
	s2_str = (const unsigned char *)s2;
	result = 0;
	while (!result && n-- && (*s1_str || *s2_str))
		result = *(s1_str++) - *(s2_str++);
	return (result);
}
