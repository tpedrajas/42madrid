/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:55:46 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/27 17:14:03 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	const char	*result;

	needle_len = ft_strlen(needle);
	result = haystack;
	if (needle_len && haystack != needle)
		result = NULL;
	while (!result && *haystack && len-- >= needle_len)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needle_len))
			result = haystack;
		else
			haystack++;
	}
	return ((char *)result);
}
