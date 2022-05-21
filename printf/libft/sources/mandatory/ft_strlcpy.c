/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:31 by tompedra          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/22 00:27:57 by tompedra         ###   ########.fr       */
=======
/*   Updated: 2022/03/26 17:08:32 by tompedra         ###   ########.fr       */
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize)
	{
		while (--dstsize && *src)
			*(dst++) = *(src++);
<<<<<<< HEAD
		*dst = '\0';
=======
		*dst = 0;
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50
	}
	return (src_len);
}
