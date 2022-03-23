/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:58:42 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 08:17:17 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_format(char **av)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(av[1]);
	if (len < 5)
	{
		ft_putstr_fd("Error: Invalid file format\n", 2);
		return (EXIT_FAILURE);
	}
	if ((ft_strncmp(".ber", &av[1][len - 4], 4) != 0)
		|| av[1][len - 5] == '.' || av[1][len - 5] == '/'
		|| av[1][len] != '\0')
	{
		ft_putstr_fd("Error: Invalid file format\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_shape(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[i]);
	++i;
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (i == 0 || i == (data->x - 1))
		{
			while (j < (data->y - 1))
			{
				if (data->map[i][j] != '1')
					return (EXIT_FAILURE);
				++j;
			}
		}
		else
			if (data->map[i][0] != '1'
				|| data->map[i][data->y - 1] != '1')
				return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_errors(t_data *data, char *av)
{
	get_map(data, av);
	if (!data->map || !line_len(data, av)
		|| !count_line(data, av))
	{
		ft_putstr_fd("Error: Troubles while reading or initializing Map\n", 2);
		return (EXIT_FAILURE);
	}
	if (count_line(data, av) == 1 || check_shape(data) == 1)
	{
		ft_putstr_fd("Error: Map has an invalid shape\n", 2);
		return (EXIT_FAILURE);
	}
	if (check_wall(data) == 1)
	{
		ft_putstr_fd("Error: Map open\n", 2);
		return (EXIT_FAILURE);
	}
	if (check_char(av) == 1 || c_count(data, av) == 1 || p_count(data) == 1
		|| e_count(data, av) == 1)
	{
		ft_putstr_fd("Error: Found an invalid char pattern\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
