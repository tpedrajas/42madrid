/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:23:26 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:47:16 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
=======
static size_t	ft_uintlen(unsigned int n)
{
	size_t	result;

	result = !n;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50
static void	ft_putnbr_fd_rec(unsigned int n, int index, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd_rec(n / 10, index - 1, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t			uintn_len;
	unsigned int	uintn;
	int				sign;

	if (!write(fd, NULL, 0))
	{
<<<<<<< HEAD
		sign = ft_nbrsign(n);
		uintn = sign * n;
		uintn_len = ft_nbrlen_base(uintn, 10) + (sign < 0);
=======
		sign = 1 - ((n < 0) << 1);
		uintn = sign * n;
		uintn_len = ft_uintlen(uintn) + (sign < 0);
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50
		if (sign < 0)
			ft_putchar_fd('-', fd);
		ft_putnbr_fd_rec(uintn, uintn_len - 1, fd);
	}
}
