/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:33:47 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/29 11:34:44 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include<stdlib.h>
# include<stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_window
{
	void	*conect;
	void	*window;
	char	**map;
	int		px;
	int		py;
	int		itens;
	int		coletados;
	int		player;
	int		saida;
}			t_window;

void	caminho(char **map, int x, int y);
int		event_exit(int key, t_window *j);
int		exit_window(t_window *j);
void	cenario(t_window *j, int k, int i);
int		event_mv(int key, t_window *j);
void	liberar_imagem(t_window *j, void **img);
void	imprimir(t_window *j, char i, int *xy, void **img);
int		verificar(t_window *j, char **map, int i, int k);
int		verificar_map(char **map);
int		verificar_caminho(char **map);
void	**images(t_window *j, int *wh);
void	free_map(t_window *j);
#endif
