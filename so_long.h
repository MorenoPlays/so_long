/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:33:47 by eda-mata          #+#    #+#             */
/*   Updated: 2024/08/05 13:44:42 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PIXEL 80
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include<stdlib.h>
# include <fcntl.h>

typedef struct s_window
{
	void	*conect;
	void	*window;
	char	**map;
	int		px;
	int		py;
	int		pixx;
	int		pixy;
	int		itens;
	int		coletados;
	int		player;
	int		saida;
	void	**img;
}			t_window;

void	caminho(char **map, int x, int y);
int		new_lines(int fd);
int		event_exit(int key, t_window *j);
int		exit_window(t_window *j);
void	cenario(t_window *j, int k, int i);
int		event_mv(int key, t_window *j);
void	liberar_imagem(t_window *j);
void	imprimir(t_window *j, char i, int *xy);
int		verificar(t_window *j, char **map, int i, int k);
int		verificar_map(char **map);
int		verificar_caminho(char **map);
void	**images(t_window *j, int *wh);
void	free_map(t_window *j);
int		resolution(t_window *j);
void	ber_map(char *str, char	*ber);
void	restore(char **map);
int		verificar_saida(char **map);
int		caminho_coletavel(char **map, int x, int y);
void	mv_porta(t_window *j, int x, int y);
void	win(t_window *j, int x, int y);
void	printmatriz(char **map);
#endif
