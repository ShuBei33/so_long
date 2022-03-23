/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:32:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 07:14:16 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********** D E F I N E **********/

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define UP 119
# define ESC 65307

# define WALL "image/choco_wall.xpm"
# define GROUND "image/ground.xpm"
# define PLAYER "image/player_grvmims.xpm"
# define COLLECT "image/collect.xpm"
# define EXIT "image/sexcite.xpm"

/******** I N C L U D E S ********/

# include <unistd.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

/********** S T R U C T **********/

typedef struct s_data
{
	char		**map;
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			y;
	int			x;
	int			i;
	int			j;
	int			ply;
	int			clct;
	int			ext;
	void		*wall;
	void		*ground;
	void		*player;
	void		*collect;
	void		*exit;
	int			pos_p_x;
	int			pos_p_y;
	int			nb_collect;
	int			nb_moves;
	char		*nb_to_print;
}				t_data;

/*********************************/
/*            M A P S            */
/*********************************/

char	*read_map(char *av);

void	display_map(t_data *data);
void	get_map(t_data *data, char *av);

/*********************************/
/*           U T I L S           */
/*********************************/

int		check_char(char *av);
int		count_line(t_data *data, char *av);
int		line_len(t_data *data, char *av);

void	init_mlx(t_data *data);
void	init_struct(t_data *data);

/*********************************/
/*          E V E N T S          */
/*********************************/

int		check_moves(int keycode, t_data *data);

void	display_moves(t_data *data, void *mlx, void *mlx_win, int move);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);

/*********************************/
/*          E R R O R S          */
/*********************************/

int		check_errors(t_data *data, char *av);
int		check_format(char **av);
int		check_mlx(t_data *data);
int		check_shape(t_data *data);
int		check_wall(t_data *data);
int		c_count(t_data *data, char *av);
int		e_count(t_data *data, char *av);
int		p_count(t_data *data);

/*********************************/
/*           C L E A N           */
/*********************************/

int		destroy_mlx(t_data *data);
int		clean_mlx(t_data *data);

void	free_map(t_data *data);
void	free_data(t_data *data);
void	free_image(t_data *data);

#endif
