/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:46:47 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 00:11:52 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_snbrlen_base(ssize_t sn, size_t base)
{
	size_t	n;
	int		result;

	result = -1;
	if (base)
	{
		n = sn * ft_nbrsign(sn);
		result = !n + (sn < 0);
		while (n)
		{
			result++;
			n /= base;
		}
	}
	return (result);
}
