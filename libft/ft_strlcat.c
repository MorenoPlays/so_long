/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:50:16 by eda-mata          #+#    #+#             */
/*   Updated: 2024/05/14 16:56:19 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	lr;

	l = 0;
	lr = 0;
	while (dst[l] != '\0' && l < size)
	{
		l++;
	}
	while (src[lr] != '\0' && (l + lr + 1) < size)
	{
		dst[l + lr] = src[lr];
		lr++;
	}
	if (l != size)
	{
		dst[l + lr] = '\0';
	}
	return (l + ft_strlen(src));
}
