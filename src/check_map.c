/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:16:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 08:37:41 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*read_map(char *av)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*line;

	buf[0] = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = 1;
	line = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		av = line;
		line = ft_strjoin(line, buf);
		free(av);
	}
	close(fd);
	if (bytes_read == -1)
		return (free(line), NULL);
	return (line);
}

void	get_map(t_data *data, char *av)
{
	char	*line;
	int		i;

	line = read_map(av);
	if (!line)
	{
		data->map = NULL;
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
			{
				data->map = NULL;
				free(line);
				return ;
			}
		}
		++i;
	}
	data->map = ft_split(line, '\n');
	free(line);
}

int	check_char(char *av)
{
	char	*line;
	int		i;

	line = read_map(av);
	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
		{
			free(line);
			return (EXIT_FAILURE);
		}
		++i;
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	count_line(t_data *data, char *av)
{
	char	*line;
	int		i;
	int		count;

	line = read_map(av);
	if (!line)
		return (0);
	count = 0;
	i = 0;
	if (line[i] && line[i] == '\n')
		return (EXIT_FAILURE);
	while (line[i])
	{
		++count;
		while (line[i] && line[i] != '\n')
			++i;
		while (line[i] && line[i] == '\n')
			++i;
	}
	data->x = count;
	free(line);
	return (count);
}

int	line_len(t_data *data, char *av)
{
	char	*line;
	int		len;
	int		i;

	line = read_map(av);
	if (!line)
		return (0);
	len = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		++len;
		++i;
	}
	data->y = len;
	free(line);
	return (len);
}
