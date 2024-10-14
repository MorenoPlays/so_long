/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extencao.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:20:38 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/05 17:35:13 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_window *j, int x, int y)
{
	j->map[x][y] = 'P';
	j->map[j->px][j->py] = '0';
	ft_putstr_fd("WIN", 1);
	free_map(j);
	liberar_imagem(j);
}

void	mv_porta(t_window *j, int x, int y)
{
	j->map[x][y] = 'P';
	j->map[j->px][j->py] = 'E';
}

void	ber_map(char *str, char	*ber)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
		i++;
	i = i - 4;
	while (str[i] == ber[k] && (str[i] && ber[k]))
	{
		i++;
		k++;
	}
	if (str[i] == '\0' && ber[k] == '\0')
		return ;
	else
	{
		ft_putstr_fd("Error", 1);
		exit(-1);
	}
}

void	printmatriz(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
	}
}

void	restore(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] == 'c'))
				map[i][j] = 'C';
			j++;
		}
		i++;
	}
}
