/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:25 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/29 14:49:28 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void swap(t_window *j, int x, int y)
{
	if(j->map[x][y] == 'E' && j->itens == j->coletados)
	{
		j->map[x][y] = 'P';
		j->map[j->px][j->py] = '0';
	}
	else if(j->map[x][y] == 'C')
	{
		j->map[x][y] = 'P';
		j->map[j->px][j->py] = '0';
		j->coletados++;
	}
	else if (j->map[x][y] == '0')
	{
		j->map[x][y] = 'P';
		j->map[j->px][j->py] = '0';
	}
}

int	event_exit(int key, t_window *j)
{
	if(key == 'q')
	{
		mlx_destroy_window(j->conect, j->window);
		free(j->conect);
		exit(0);
	}
	return (0);
}

int	event_mv(int key, t_window *j)
{
	if(key == 'd' && j->map[j->px][j->py+1] != '1')
		swap(j, j->px, j->py+1);
	else if(key == 'w' && j->map[j->px-1][j->py] != '1')
		swap(j, j->px-1, j->py);
	else if(key == 's' && j->map[j->px+1][j->py] != '1')
		swap(j, j->px+1, j->py);
	else if(key == 'a' && j->map[j->px][j->py-1] != '1')
		swap(j, j->px, j->py-1);
	cenario(j, 0, 0);
	return (0);
}

int	exit_window(t_window *j)
{
	mlx_destroy_window(j->conect, j->window);
	free(j->conect);
	exit(0);
	return (0);
}
