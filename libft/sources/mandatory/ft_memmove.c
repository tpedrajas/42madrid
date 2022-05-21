/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:13 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:44:30 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_str;
	const char	*src_str;
	ssize_t		diff_pos;

	diff_pos = dst - src;
	if (diff_pos)
	{
		dst_str = dst;
		src_str = src;
		if (diff_pos < 0)
			ft_memcpy(dst, src, len);
		else
		{
			while (len)
			{
				len--;
				dst_str[len] = src_str[len];
			}
		}
	}
	return (dst);
}
