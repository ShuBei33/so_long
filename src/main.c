/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:26:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 08:23:56 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->collect = 0;
	data->exit = 0;
	data->player = 0;
	data->nb_collect = 0;
	data->nb_moves = 0;
	data->nb_to_print = NULL;
	data->i = 0;
	data->j = 0;
}

void	display_map(t_data *data)
{
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall, data->j * 80, data->i * 80);
			if (data->map[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->ground, data->j * 80, data->i * 80);
			if (data->map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->player, data->j * 80, data->i * 80);
			if (data->map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->collect, data->j * 80, data->i * 80);
			if (data->map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit, data->j * 80, data->i * 80);
			data->j++;
		}
		data->i++;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_putstr_fd("Error: mlx initialization failed\n", 2);
		return ;
	}
	data->win = mlx_new_window(data->mlx, (data->y * 80),
			(data->x * 80), "My Little Bunbun");
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->width, &data->height);
	data->ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->width, &data->height);
	data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->width, &data->height);
}

int	check_mlx(t_data *data)
{
	if (data->win == NULL || data->ground == NULL
		|| data->player == NULL || data->collect == NULL
		|| data->exit == NULL || data->wall == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (ac != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	if (check_format(av) == 1)
		return (EXIT_FAILURE);
	if (check_errors(&data, av[1]) == 1)
		return (free_map(&data), 1);
	init_mlx(&data);
	if (check_mlx(&data) == 1)
		clean_mlx(&data);
	display_map(&data);
	mlx_hook(data.win, 33, 131072, &destroy_mlx, &data);
	mlx_hook(data.win, 2, 1L << 0, check_moves, &data);
	mlx_loop(data.mlx);
	return (0);
}
