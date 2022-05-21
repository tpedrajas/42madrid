/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:05:59 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:36:53 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_max_ulong(void)
{
	return (~0UL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	result_len;
	char	*result;

	result = NULL;
	if (!count || ft_max_ulong() / count >= size)
	{
		result_len = count * size;
		result = (char *)malloc(sizeof(char) * result_len);
		if (result)
			ft_bzero(result, result_len);
	}
	return (result);
}
