/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullonglen_base_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:46:47 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/13 21:51:28 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ullonglen_base_extra(size_t n, size_t base)
{
	int		result;

	if (!base)
		result = -1;
	else
	{
		result = !n;
		while (n)
		{
			result++;
			n /= base;
		}
	}
	return (result);
}
