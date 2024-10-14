/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:47:52 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/05 13:44:06 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process(t_window *j)
{
	mlx_key_hook(j->window, event_exit, j);
	mlx_key_hook(j->window, event_mv, j);
	mlx_hook(j->window, 17, 1L, exit_window, j);
	mlx_loop(j->conect);
}

char	**read_map(int fd, int new_lines)
{
	int		j;
	int		i;
	char	temp[1];
	char	**map;

	j = 0;
	map = malloc(new_lines * sizeof(char *));
	while (j < new_lines - 1)
		map[j++] = malloc(1024 * sizeof(char));
	j = 0;
	temp[0] = ' ';
	while (j < (new_lines - 1))
	{
		i = 0;
		while (temp[0] != '\n')
		{
			read(fd, temp, 1);
			map[j][i++] = temp[0];
		}
		temp[0] = '\0';
		map[j++][i] = '\0';
	}
	map[j] = NULL;
	close(fd);
	return (map);
}

void	cenario(t_window *j, int k, int i)
{
	int		xy[2];

	xy[1] = 0;
	while (j->map[i] != NULL)
	{
		k = 0;
		xy[0] = 0;
		while (j->map[i][k])
		{
			if (j->map[i][k] == 'P')
			{
				j->px = i;
				j->py = k;
			}
			imprimir(j, j->map[i][k], xy);
			xy[0] += 80;
			k++;
		}
		xy[1] += 80;
		i++;
	}
}

void	start_game(char **map)
{
	t_window	j;
	int			wh[2];

	j.map = map;
	j.itens = 0;
	j.coletados = 0;
	j.player = 0;
	j.saida = 0;
	if ((verificar(&j, map, 0, 0) == 0 && verificar_map(map) == 0)
		&& (verificar_caminho(map) == 0) && resolution(&j) == 0)
	{
		j.conect = mlx_init();
		j.window = mlx_new_window(j.conect, j.pixy * PIXEL - 80,
				j.pixx * PIXEL, "so_long");
		j.img = images(&j, wh);
		cenario(&j, 0, 0);
		process(&j);
	}
	else
	{
		free_map(&j);
		ft_putstr_fd("Error\n", 1);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		j;
	char	**map;

	if (argc == 2 && argv[1])
	{
		j = 0;
		ber_map(argv[1], ".ber");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error\n", 1);
			exit(-1);
		}
		j = new_lines(fd);
		fd = open(argv[1], O_RDONLY);
		map = read_map(fd, j);
		start_game(map);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
