/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:00:48 by eda-mata          #+#    #+#             */
/*   Updated: 2024/05/16 10:15:06 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 4294967295;
	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > size_max / size)
		return (NULL);
	ptr = malloc(count * size);
	ft_bzero(ptr, size * count);
	return (ptr);
}
