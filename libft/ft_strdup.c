/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:18:19 by eda-mata          #+#    #+#             */
/*   Updated: 2024/05/16 10:30:01 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
