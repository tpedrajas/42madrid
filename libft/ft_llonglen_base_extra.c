/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llonglen_base_extra.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:46:47 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/13 21:50:01 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llonglen_base_extra(ssize_t n, size_t base)
{
	size_t	ullong_n;
	int		result;

	if (!base)
		result = -1;
	else
	{
		if (n < 0)
			ullong_n = -n;
		else
			ullong_n = n;
		result = !ullong_n | (n < 0);
		while (ullong_n)
		{
			result++;
			ullong_n /= base;
		}
	}
	return (result);
}
