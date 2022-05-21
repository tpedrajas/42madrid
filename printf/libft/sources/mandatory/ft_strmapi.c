/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:27:44 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/27 15:27:44 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*result;

	result = NULL;
	if (s)
	{
		result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (result)
		{
			index = -1;
			while (s[++index])
				result[index] = f(index, s[index]);
<<<<<<< HEAD
			result[index] = '\0';
=======
			result[index] = 0;
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50
		}
	}
	return (result);
}
