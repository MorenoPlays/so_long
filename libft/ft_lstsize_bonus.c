/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 01:30:37 by eda-mata          #+#    #+#             */
/*   Updated: 2024/05/17 01:36:18 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*str;

	i = 0;
	str = (t_list *)lst;
	while (str)
	{
		i++;
		str = str->next;
	}
	return (i);
}
