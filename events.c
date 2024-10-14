/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:25 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/05 13:43:48 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap(t_window *j, int x, int y)
{
	static int	step;

	if (j->map[x][y] == 'E' && j->itens == j->coletados)
		win(j, x, y);
	else if (j->map[x][y] == 'E')
		mv_porta(j, x, y);
	else if (j->map[x][y] == 'C')
	{
		j->map[x][y] = 'P';
		j->map[j->px][j->py] = '0';
		j->coletados++;
		ft_putnbr_fd(++step, 1);
		write(1, "\n", 1);
	}
	else if (j->map[x][y] == '0' || j->map[x][y] == 'F')
	{
		j->map[x][y] = 'P';
		j->map[j->px][j->py] = '0';
		ft_putnbr_fd(++step, 1);
		write(1, "\n", 1);
	}
}

int	event_exit(int key, t_window *j)
{
	if (key == 65307)
	{
		mlx_destroy_window(j->conect, j->window);
		free(j->conect);
		exit(0);
	}
	return (0);
}

int	event_mv(int key, t_window *j)
{
	if (key == 'd' && j->map[j->px][j->py + 1] != '1')
		swap(j, j->px, j->py + 1);
	else if (key == 'w' && j->map[j->px - 1][j->py] != '1')
		swap(j, j->px - 1, j->py);
	else if (key == 's' && j->map[j->px + 1][j->py] != '1')
		swap(j, j->px + 1, j->py);
	else if (key == 'a' && j->map[j->px][j->py - 1] != '1')
		swap(j, j->px, j->py - 1);
	else if (key == 65307)
	{
		mlx_destroy_window(j->conect, j->window);
		free(j->conect);
		exit(0);
	}
	mlx_clear_window(j->conect, j->window);
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

int	resolution(t_window *j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (j->map[i] != NULL)
		i++;
	j->pixx = i;
	while (j->map[0][k] != '\0')
		k++;
	j->pixy = k;
	i = 0;
	while (j->map[i] != NULL)
	{
		k = 0;
		while (j->map[i][k] != '\0')
			k++;
		if (k != j->pixy)
			return (-1);
		i++;
	}
	if (k == i)
		return (-1);
	return (0);
}
