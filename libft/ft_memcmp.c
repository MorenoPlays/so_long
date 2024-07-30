/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:57:49 by eda-mata          #+#    #+#             */
/*   Updated: 2024/05/15 14:22:08 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*si1;
	unsigned char	*si2;
	size_t			i;

	i = 0;
	si1 = (unsigned char *)s1;
	si2 = (unsigned char *)s2;
	while (i < n)
	{
		if (si1[i] == si2[i])
		{
			i++;
		}
		else
		{
			return (si1[i] - si2[i]);
		}
	}
	return (0);
}
