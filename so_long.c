/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:47:52 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/26 15:47:55 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_lines(int fd)
{
	int		i;
	int		j;
	char	str[2];

	i = -1;
	j = 0;
	while (i != 0)
	{
		i = read(fd, str, 1);
		if (str[0] == '\n')
			j++;
	}
	return (j);
}

char	**read_map(int fd, int new_lines)
{
	int		j;
	int		i;
	char		temp[1];
	char	**map;

	j = 0;
	map = malloc(new_lines * sizeof(char *));
	while (j < new_lines)
		map[j++] = malloc(1024 * sizeof(char));
	j = 0;
	while(j < (new_lines-1))
	{
		i = 0;
		while(temp[0] != '\n')
		{
			read(fd, temp, 1);
			map[j][i]= temp[0];
			i++;
		}
		temp[0]='\0';
		map[j][i]='\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

void	cenario(t_window *j, int k, int i)
{
	int		wh[2];
	int		xy[2];
	void	**img;

	xy[1] = 0;
	img = images(j, wh);
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
			imprimir(j, j->map[i][k], xy, img);
			xy[0] += 40;
			k++;
		}
		xy[1] += 30;
		i++;
	}
	liberar_imagem(j, img);
}

void	start_game(char **map)
{
	t_window	j;

	j.map = map;
	j.itens = 0;
	j.coletados = 0;
	j.player = 0;
	j.saida = 0;
	if ((verificar(&j, map, 0, 0) == 0 && verificar_map(map) == 0)
		&& (verificar_caminho(map) == 0))
	{
		j.conect = mlx_init();
		j.window = mlx_new_window(j.conect, 1080, 700, "so_long");
		cenario(&j, 0, 0);
		mlx_hook(j.window, 17, 1L, exit_window, &j);
		mlx_key_hook(j.window, event_exit, &j);
		mlx_key_hook(j.window, event_mv, &j);
		mlx_loop(j.conect);
	}
	else
	{
		perror("Error\nMapa com erro!");
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		j;
	char	**map;

	if (argc == 2)
	{
		j = 0;
		fd = open(argv[1], O_RDONLY);
		j = new_lines(fd);
		fd = open(argv[1], O_RDONLY);
		map = read_map(fd, j);
		start_game(map);
	}
	return (0);
}
