/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:52:48 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/15 22:22:46 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_moves(t_data *data, void *mlx, void *mlx_win, int move)
{
	mlx_put_image_to_window(mlx, mlx_win, data->player,
		data->pos_p_y * 80, data->pos_p_x * 80);
	mlx_put_image_to_window(mlx, mlx_win, data->wall,
		0 * 80, 0 * 80);
	if (move == UP)
	{
		mlx_put_image_to_window(mlx, mlx_win, data->ground,
			data->pos_p_y * 80, (data->pos_p_x + 1) * 80);
	}
	else if (move == DOWN)
	{
		mlx_put_image_to_window(mlx, mlx_win, data->ground,
			data->pos_p_y * 80, (data->pos_p_x - 1) * 80);
	}
	else if (move == RIGHT)
	{
		mlx_put_image_to_window(mlx, mlx_win, data->ground,
			(data->pos_p_y - 1) * 80, data->pos_p_x * 80);
	}
	else if (move == LEFT)
	{
		mlx_put_image_to_window(mlx, mlx_win, data->ground,
			(data->pos_p_y + 1) * 80, data->pos_p_x * 80);
	}
}
