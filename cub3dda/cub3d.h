/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:25:22 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/01/31 17:38:59 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# define TILE_SIZE 64
# define FLT_MAX 3.402823e+38

unsigned long long				g_height;
unsigned long long				g_width;
char							*g_so;
char							*g_no;
char							*g_ea;
char							*g_we;
char							*g_spr;
int 							g_fr; 
int 							g_fg; 
int 							g_fb;  
int 							g_cr; 
int 							g_cg;
int 							g_cb;
int 							g_map_st;
char							*g_map;
char							**g_marrays;
int 							g_mwidth;
int 							g_mheight;
char							**g_allmap;
char							**g_allmap_with_spaces;
int 							g_ray_up;
int 							g_ray_d;
int 							g_ray_r;
int 							g_ray_l;
int								g_p;
char							*g_file;
int								g_save;
int								g_sp;
typedef struct 		s_ray
{
	float						wallhitx;
	float	wallhity;
	float	distance;
	float	rayAngle; 
	int		g_washvert;
	int		ray_up;
	int		ray_d;
	int		ray_r;
	int		ray_l;
}					g_t_ray;

g_t_ray 	rays[3000];

typedef struct rays
{
	float g_xinter;
	float g_yintercept;
	float xstep;
	float ystep;
	int foundhorzhit;
	int foundverhit;
	float horzhitx;
	float horzhity;
	float verthitx;
	float verthity;
	float nexthorX;
	float nexthorY;
	float nextverx;
	float nextvery;
	float hodst;
	float vdist;
	float xc;
	float yc;
} t_ray;
t_ray g_ray;



typedef struct s_data {
	void *img;
	char *addr;
	int bpp;
	int ln;
	int endian;
}               t_data;

t_data img;
t_data no;
t_data south;
t_data east;
t_data west;

typedef struct player {
	float x;
	float y;
	float FOV;
	float side_step;
	float radius;
	int turnDirection;
	int walkDirection;
	float rtang;
	float MoveSpeed;
	float rotationSpeed; 
	
}   t_player;

t_player player;

typedef struct s_vars{
	void *mlx;
	void *mlx_wind;

} t_vars;
t_vars vars;
typedef struct colors
{
	float perpdist;
	float distprojection;
	float wallprojection;
	int strip_h;
	int walltop;
	int wallbot;
	int xoffset;
	int yoffset;
	int dist;
}   t_color;
t_color g_col;
void 			draw_map();
float 			angle_ray(float rayangle);
int				outtil(int fd, char **rest, char **line);
int				get_next_line(int fd, char **line);
char			*kayn_ster(char		*str);
char			*ft_substr(char		*s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
int				ft_strlen( char *s);
char			*ft_strjoin(char *s1, char *s2);
void			treat_resolution(char *line);
void			map_funct(char *line);
int 			read_map();
void			treat_south(char *line);
void			init_param();
int				params();
void			error_gestion(int i);
void			DDA(int X0, int Y0, int X1, int Y1) ;
int 			numbers_of_parameters(char *str,char c);
char			**ft_split(char  *s, char c);
int 			is_digit(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int 			ft_isdigit(int c);
int				ft_atoi(const char *str);
int				resolution(unsigned long long  width,unsigned long long  height);
void			get_the_resolution(unsigned long long width, unsigned long long height);
char			**free_memory(char **str);
void			treat_c(char *line);
int 			get_c(int r, int g, int b);
void			treat_f(char *line);
int 			get_f(int r, int g, int b);
void			white_spaces(char *str);
void			ft_putstr(char *str);
void			ft_write(char c);
void			treat_no(char *line);
void			check_ext(char *str, char c);
void			treat_south(char *line);
void			treat_west(char *line);
void			treat_east(char *line);
void			treat_sprite(char *line);
void			read_map_line(char *str);
char			*ft_strjoin_line(char  *s1, char  *s2);
void			check_map_arrays(char *str);
void rende_3d();
int quit(void);
void		split_map(void);
void		check_arrays();
void		fill_g_allmap();
void		fill_spaces(char **str);
void		 fill_map(char **str);
void		check_close(char **str);
void		fill_map_with_one(char **str);
void		check_ceiling(char *str);
int			height_resolution(int h);
int 		width_resolution(int w);
void		intialize_player();
void		draw_player(char **str);
void		check_player(char **str);
void		check_play_exist();
void		init_player(char x,int i, int j);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_in_map(int l, int x, int y, int color);
void		 update();
void		move_player();
void		render();
void	free_all(char *str, char **s);
int 		key_press(int keycode);
int 		release(int keycode);
int 		play();
void		draw_square(int l, int color, int x,int y);
void		intialize_rays(float rayAngle);
void		cast_rays(void);
void		check_width();
int 		walls(float x, float y);
void		render_rays(int i);
void		vertical(float angle);
void		horizontal(float angle);
float		dstpnts(float x, float y, float x0, float y0);

#endif  