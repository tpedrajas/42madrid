/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:41:44 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 00:11:47 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrsign(ssize_t sn)
{
	int	result;

	result = 1 - ((sn < 0) << 1);
	return (result);
}
