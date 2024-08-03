/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:43:44 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/30 06:46:17 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**images(t_window *j, int *wh)
{
	void	**img;

	img = malloc(6 * sizeof(void *));
	img[0] = mlx_xpm_file_to_image(j->conect,
			"SRC/paredes/curva.xpm", &wh[0], &wh[1]);
	img[1] = mlx_xpm_file_to_image(j->conect,
			"SRC/paredes/terra.xpm", &wh[0], &wh[1]);
	img[2] = mlx_xpm_file_to_image(j->conect,
			"SRC/person/man.xpm", &wh[0], &wh[1]);
	img[3] = mlx_xpm_file_to_image(j->conect,
			"SRC/person/saida.xpm", &wh[0], &wh[1]);
	img[4] = mlx_xpm_file_to_image(j->conect,
			"SRC/item/bau.xpm", &wh[0], &wh[1]);
	img[5] = NULL;
	return (img);
}

void	imprimir(t_window *j, char i, int *xy, void **img)
{
	if (i == '1')
		mlx_put_image_to_window(j->conect, j->window, img[0], xy[0], xy[1]);
	else if (i == '0' || i == 'F')
		mlx_put_image_to_window(j->conect, j->window, img[1], xy[0], xy[1]);
	else if (i == 'P')
		mlx_put_image_to_window(j->conect, j->window, img[2], xy[0], xy[1]);
	else if (i == 'E')
		mlx_put_image_to_window(j->conect, j->window, img[3], xy[0], xy[1]);
	else if (i == 'C')
		mlx_put_image_to_window(j->conect, j->window, img[4], xy[0], xy[1]);
}

void	liberar_imagem(t_window *j, void **img)
{
	int	i;

	i = 0;
	while (img[i] != NULL)
	{
		mlx_destroy_image(j->conect, img[i]);
		i++;
	}
	free(img[i]);
}

void	free_map(t_window *j)
{
	int	i;

	i = 0;
	while(j->map[i]!= NULL)
	{
		free(j->map[i]);
		i++;
	}
	free(j->map);
	exit(0);
}
