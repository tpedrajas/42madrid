/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:08 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/26 22:53:04 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_str;
	const char	*src_str;
	void		*result;

	result = NULL;
	if (dst || src)
	{
		dst_str = dst;
		src_str = src;
		while (n--)
			*(dst_str++) = *(src_str++);
		result = dst;
	}
	return (result);
}
