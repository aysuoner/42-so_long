/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:07:35 by aoner             #+#    #+#             */
/*   Updated: 2022/07/02 18:05:55 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 100
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**collect_lines;
	int		count_lines;
	int		fd;
	void	*mlx;
	void	*win;
	void	*imgw;
	void	*imge;
	void	*imgp;
	void	*imgc;
	void	*imgs;
	int		*keyp;
	int		w;
	int		h;
	int		px;
	int		py;
	int		step;
	int		coins;
	char	*line;
	int		fdxpm;
	char	**xpm;
	int		x;
	int		y;
	size_t	i;
	int		li;
}t_map;

int			main(int argc, char **argv);
void		maintwo(t_map *map);
void		save_map(char *path, t_map *map);
int			ft_printf(const char *str, ...);

//asistant....
char		*get_next_line(int fd);
char		*ft_read_and_save(int fd, char *save);
char		*ft_save(char *save);
char		*ft_get_line(char *save);
int			has_return(char *str);
size_t		ft_strlengnl(const char *s);
char		*ft_strjoingnl(char *s1, char const *s2);
int			ft_rvstrncmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);

//map_ctrl....
void		fd_ctrl(char *path, t_map *map);
int			map_linecount_ctrl(t_map *map);
void		map_wall_ctrl(t_map *map);
void		top_wall_ctrl(t_map *map, size_t li);
void		middle_walls_ctrl(t_map *map, size_t li);
void		bot_wall_ctrl(t_map *map, size_t li);
void		map_rectanglr_ctrl(t_map *map);
void		map_char_ctrl(t_map *map);
int			char_e_ctrl(t_map *map);
int			char_p_ctrl(t_map *map);
int			char_zero_ctrl(t_map *map);
int			char_c_ctrl(t_map *map);
void		map_difchar_ctrl(t_map *map);
int			difchar_ctrl(t_map *map);
int			row_ctrl(t_map *map);
void		xpm_ctrl(t_map *map);

//error_funcs
void		error_map(t_map *map);
void		free_map_and_mlx(t_map *map);
void		error_xpm(t_map *map);

//put_the_imgs
void		pinpointing_the_chars(t_map *map);
void		from_xpm_to_img(t_map *map);
void		if_1(t_map *map);
void		if_e(t_map *map);
void		if_p(t_map *map);
void		if_c(t_map *map);
void		if_zero(t_map *map);
void		if_newline(t_map *map);

//key_event
int			key_events(int keycode, t_map *x);
void		code_13(t_map *x);
void		event_13(t_map *x);
void		code_1(t_map *x);
void		event_1(t_map *x);
void		code_zero(t_map *x);
void		event_zero(t_map *x);
void		code_2(t_map *x);
void		event_2(t_map *x);
int			close_x(t_map *x);

# define PLAYER "./pics/player64.xpm"
# define COLLECT "./pics/coin64.xpm"
# define EXIT "./pics/exit64.xpm"
# define WALL "./pics/wall64.xpm"
# define SPACE "./pics/back64.xpm"

#endif
