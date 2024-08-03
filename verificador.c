/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificador.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:07:47 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/02 13:07:53 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	caminho(char **map, int x, int y)
{
	if ((map[x][y] != '0' && map[x][y] != 'P')
		&& (map[x][y] != 'C' && map[x][y] != 'E'))
		return ;
	if (map[x][y] == '0')
		map[x][y] = 'F';
	caminho(map, x + 1, y);
	caminho(map, x - 1, y);
	caminho(map, x, y + 1);
	caminho(map, x, y - 1);
}

int	verificar_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if ((map[i][j] != '1' && map[i][j + 1] == '\n')
				|| (map[i][0] != '1'))
				return (-1);
			else if ((map[0][j] != '1' ) ||
				(map[i][j] != '1' && map[i + 1] == NULL))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verificar(t_window *j, char **map, int i, int k)
{
	while (map[i] != NULL)
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'P')
				j->player++;
			else if (map[i][k] == 'E')
				j->saida++;
			else if (map[i][k] == 'C')
				j->itens++;
			else if (map[i][k] != '0' && map[i][k] != 'F'
				&& map[i][k] != '1' && map[i][k] != '\n')
				return (-1);
			k++;
		}
		i++;
	}
	if (j->player != 1 || (j->saida != 1 || j->itens < 1))
		return (-1);
	return (0);
}

int	verificar_bloqueio(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
			{
				if ((map[i + 1][j] == '0' || map[i - 1][j] == '0')
					|| map[i][j + 1] == '0' || map[i][j - 1] == '0')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	verificar_caminho(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				caminho(&*map, i, j);
			j++;
		}
		i++;
	}
	return (verificar_bloqueio(map));
}
