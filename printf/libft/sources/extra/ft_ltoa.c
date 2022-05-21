/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:52:38 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/22 00:58:17 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ltoa_rec(char *str, unsigned long n, int index)
{
	if (n < 10)
		str[index] = n + '0';
	else
	{
		ft_itoa_rec(str, n / 10, index - 1);
		str[index] = (n % 10) + '0';
	}
}

char	*ft_ltoa(long n)
{
	unsigned long	ulongn;
	int				sign;
	size_t			result_len;
	char			*result;

	sign = ft_nbrsign(n);
	ulongn = sign * n;
	result_len = ft_nbrlen_base(ulongn, 10) + (sign < 0);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result)
	{
		if (sign < 0)
			result[0] = '-';
		result[result_len] = 0;
		ft_ltoa_rec(result, ulongn, result_len - 1);
	}
	return (result);
}