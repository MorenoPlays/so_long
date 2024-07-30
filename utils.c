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

int	verificar_map(char **map)
{
	int	i;
	int	j
	
	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != '1' && map[i][j+1] == '\0')
				return (-1);
			j++;
		}
		i++;
	}
}

int	verificar(t_window *j, char **map, int i, int k)
{
	while(map[i] != NULL)
	{
		k = 0;
		while(map[i][k])
		{
			if(map[i][k]=='P')
				j->player++;
			else if(map[i][k]=='E')
				j->saida++;
			else if(map[i][k]=='C')
				j->itens++;
			k++;
		}
		i++;
	}
	if(j->player !=1 || j->saida != 1 || j->itens < 1)
		return (-1);
	return (0);
}

void	imprimir(t_window *j, char i, int *xy, void **img)
{
	if(i == '1')
		mlx_put_image_to_window(j->conect,j->window,img[0],xy[0], xy[1]);
	else if (i == '0')
		mlx_put_image_to_window(j->conect, j->window,img[1],xy[0], xy[1]);
	else if (i == 'P')
		mlx_put_image_to_window(j->conect, j->window,img[2],xy[0], xy[1]);
	else if (i == 'E')
		mlx_put_image_to_window(j->conect, j->window,img[3],xy[0], xy[1]);
	else if (i == 'C')
		mlx_put_image_to_window(j->conect, j->window,img[4],xy[0], xy[1]);
}

void	liberar_imagem(void **img)
{
	int	i;

	i = 0;
	while(img[i] != NULL)
	{
		free(img[i]);
		i++;
	}
	free(img[i]);

}
