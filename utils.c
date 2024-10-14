/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:43:44 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/05 13:44:30 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**images(t_window *j, int *wh)
{
	void	**img;

	img = malloc(6 * sizeof(void *));
	img[0] = mlx_xpm_file_to_image(j->conect,
			"textures/paredes/curva.xpm", &wh[0], &wh[1]);
	img[1] = mlx_xpm_file_to_image(j->conect,
			"textures/paredes/terra.xpm", &wh[0], &wh[1]);
	img[2] = mlx_xpm_file_to_image(j->conect,
			"textures/person/man.xpm", &wh[0], &wh[1]);
	img[3] = mlx_xpm_file_to_image(j->conect,
			"textures/person/saida.xpm", &wh[0], &wh[1]);
	img[4] = mlx_xpm_file_to_image(j->conect,
			"textures/item/bau.xpm", &wh[0], &wh[1]);
	img[5] = NULL;
	return (img);
}

void	imprimir(t_window *j, char i, int *xy)
{
	if (i == '1')
		mlx_put_image_to_window(j->conect, j->window, j->img[0], xy[0], xy[1]);
	else if (i == '0' || i == 'F')
		mlx_put_image_to_window(j->conect, j->window, j->img[1], xy[0], xy[1]);
	else if (i == 'P')
		mlx_put_image_to_window(j->conect, j->window, j->img[2], xy[0], xy[1]);
	else if (i == 'E')
		mlx_put_image_to_window(j->conect, j->window, j->img[3], xy[0], xy[1]);
	else if (i == 'C')
		mlx_put_image_to_window(j->conect, j->window, j->img[4], xy[0], xy[1]);
}

void	liberar_imagem(t_window *j)
{
	int	i;

	i = 0;
	while (j->img[i] != NULL)
	{
		mlx_destroy_image(j->conect, j->img[i]);
		i++;
	}
	free(j->img[i]);
	free(j->img);
	mlx_clear_window(j->conect, j->window);
	mlx_destroy_window(j->conect, j->window);
	mlx_destroy_display(j->conect);
	free(j->conect);
	exit(0);
}

void	free_map(t_window *j)
{
	int	i;

	i = 0;
	while (j->map[i] != NULL)
	{
		free(j->map[i]);
		i++;
	}
	free(j->map[i]);
	free(j->map);
}

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
	close(fd);
	return (j);
}
