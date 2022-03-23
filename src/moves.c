/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:18:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 00:35:23 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->pos_p_x - 1][data->pos_p_y] != '1')
	{
		if (data->map[data->pos_p_x - 1][data->pos_p_y] == 'C')
			data->nb_collect += 1;
		if (data->map[data->pos_p_x - 1][data->pos_p_y] == 'E'
			&& data->nb_collect != data->clct)
			return ;
		if (data->map[data->pos_p_x - 1][data->pos_p_y] == 'E'
			&& data->nb_collect == data->clct)
			destroy_mlx(data);
		data->map[data->pos_p_x - 1][data->pos_p_y] = 'P';
		data->map[data->pos_p_x][data->pos_p_y] = '0';
		data->pos_p_x -= 1;
		data->nb_moves += 1;
		data->nb_to_print = ft_itoa(data->nb_moves);
		display_moves(data, data->mlx, data->win, UP);
		mlx_string_put(data->mlx, data->win, 0 * 80, 1 * 80, 0x0000FF00,
			data->nb_to_print);
	}
	free(data->nb_to_print);
}

void	move_down(t_data *data)
{
	if (data->map[data->pos_p_x + 1][data->pos_p_y] != '1')
	{
		if (data->map[data->pos_p_x + 1][data->pos_p_y] == 'C')
			data->nb_collect += 1;
		if (data->map[data->pos_p_x + 1][data->pos_p_y] == 'E'
			&& data->nb_collect != data->clct)
			return ;
		if (data->map[data->pos_p_x + 1][data->pos_p_y] == 'E'
			&& data->nb_collect == data->clct)
			destroy_mlx(data);
		data->map[data->pos_p_x + 1][data->pos_p_y] = 'P';
		data->map[data->pos_p_x][data->pos_p_y] = '0';
		data->pos_p_x += 1;
		data->nb_moves += 1;
		data->nb_to_print = ft_itoa(data->nb_moves);
		display_moves(data, data->mlx, data->win, DOWN);
		mlx_string_put(data->mlx, data->win, 0 * 80, 1 * 80, 0x0000FF00,
			data->nb_to_print);
	}
	free(data->nb_to_print);
}

void	move_left(t_data *data)
{
	if (data->map[data->pos_p_x][data->pos_p_y - 1] != '1')
	{
		if (data->map[data->pos_p_x][data->pos_p_y - 1] == 'C')
			data->nb_collect += 1;
		if (data->map[data->pos_p_x][data->pos_p_y - 1] == 'E'
			&& data->nb_collect != data->clct)
			return ;
		if (data->map[data->pos_p_x][data->pos_p_y - 1] == 'E'
			&& data->nb_collect == data->clct)
			destroy_mlx(data);
		data->map[data->pos_p_x][data->pos_p_y - 1] = 'P';
		data->map[data->pos_p_x][data->pos_p_y] = '0';
		data->pos_p_y -= 1;
		data->nb_moves += 1;
		data->nb_to_print = ft_itoa(data->nb_moves);
		display_moves(data, data->mlx, data->win, LEFT);
		mlx_string_put(data->mlx, data->win, 0 * 80, 1 * 80, 0x0000FF00,
			data->nb_to_print);
	}
	free(data->nb_to_print);
}

void	move_right(t_data *data)
{
	if (data->map[data->pos_p_x][data->pos_p_y + 1] != '1')
	{
		if (data->map[data->pos_p_x][data->pos_p_y + 1] == 'C')
			data->nb_collect += 1;
		if (data->map[data->pos_p_x][data->pos_p_y + 1] == 'E'
			&& data->nb_collect != data->clct)
			return ;
		if (data->map[data->pos_p_x][data->pos_p_y + 1] == 'E'
			&& data->nb_collect == data->clct)
			destroy_mlx(data);
		data->map[data->pos_p_x][data->pos_p_y + 1] = 'P';
		data->map[data->pos_p_x][data->pos_p_y] = '0';
		data->pos_p_y += 1;
		data->nb_moves += 1;
		data->nb_to_print = ft_itoa(data->nb_moves);
		display_moves(data, data->mlx, data->win, RIGHT);
		mlx_string_put(data->mlx, data->win, 0 * 80, 1 * 80, 0x0000FF00,
			data->nb_to_print);
	}
	free(data->nb_to_print);
}

int	check_moves(int keycode, t_data *data)
{
	data->nb_to_print = NULL;
	if (keycode == UP)
		move_up(data);
	else if (keycode == DOWN)
		move_down(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == LEFT)
		move_left(data);
	else if (keycode == ESC)
		destroy_mlx(data);
	return (EXIT_SUCCESS);
}
