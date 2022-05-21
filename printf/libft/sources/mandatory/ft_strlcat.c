/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:26 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/26 18:09:56 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	max_append;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize && dst_len < dstsize)
	{
		max_append = dstsize - dst_len - 1;
		if (max_append > src_len)
			max_append = src_len;
		dst += dst_len;
		while (max_append--)
			*(dst++) = *(src++);
		*dst = 0;
	}
	else
		dst_len = dstsize;
	return (src_len + dst_len);
}
