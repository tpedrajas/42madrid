/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:46:47 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/18 23:39:02 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nbrlen_base(size_t n, size_t base)
{
	int		result;

	result = -1;
	if (base)
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
