/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:51:51 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 11:01:40 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	c_count(t_data *data, char *av)
{
	char	*line;
	int		i;
	int		c_count;

	line = read_map(av);
	if (!line)
		return (0);
	c_count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			++c_count;
		++i;
	}
	data->clct = c_count;
	free(line);
	if (c_count < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	p_count(t_data *data)
{
	int		i;
	int		j;
	int		p_count;

	p_count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				++p_count;
				data->pos_p_x = i;
				data->pos_p_y = j;
			}
			++j;
		}
		++i;
	}
	data->ply = p_count;
	if (p_count != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	e_count(t_data *data, char *av)
{
	char	*line;
	int		i;
	int		e_count;

	line = read_map(av);
	if (!line)
		return (0);
	e_count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			++e_count;
		++i;
	}
	data->ext = e_count;
	free(line);
	if (e_count != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
