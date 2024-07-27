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

#include "minilibx-linux/mlx.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct s_janela
{
	void	*conexao;
	void	*window;
}	t_janela;

int	evento(int key, t_janela *j)
{
	if(key == 'q')
	{
		mlx_destroy_window(j->conexao, j->window);
		free(j->conexao);
		exit(0);
	}
	return (0);
}

int	sair(t_janela *j)
{

	
	mlx_destroy_window(j->conexao, j->window);
	free(j->conexao);
	exit(0);
	return (0);
}

int main()
{
	t_janela	j;

	j.conexao = mlx_init();
	j.window = mlx_new_window(j.conexao, 600, 400, "so_long");
	mlx_hook(j.window, 17,1L << 0,sair, &j);
	mlx_key_hook(j.window, evento, &j);
	mlx_loop(j.conexao);
	
	return 0;
}
