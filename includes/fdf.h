/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 15:50:08 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# define W_WIDTH 2000
# define W_HEIGHT 1000
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MlcErr "Error. Malloc alocation failed."
# define MapError "Error. Map is invalid."

typedef struct s_img
{
	void	*img_ptr;
	char	*add_ptr;
	int 	bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_pixel
{
	double x;
	double y;
	double z;
	int color;
}				t_pixel;

typedef struct	s_options
{
	double x0;
	double y0;
	double z0;
	double iso_scale;
	short	coloured;
	int max;
	int min;
}				t_options;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	col;
	int row;
	t_img		*image;
	t_options *options;
}				t_fdf;


// utilities.c
void	ft_display_error(int condition, char *str);
void	ft_free_args(char ***args, int i);
// initialize.c
void	ft_initialize_fdf(t_fdf *fdf);
void	ft_initialize_map(t_fdf *fdf);
// map_reader.c
void	ft_read_map(int fd, t_list **lst, t_fdf *fdf);
static	void	ft_save_coordinats(char **args, t_list **lst, int y, t_fdf *fdf);
static	int	ft_count_width(char **line_args);
//image.c
void	ft_set_pixel_to_image(t_fdf *fdf, int x, int y, int color);
void	ft_initialize_image(t_fdf *fdf);
void	ft_clear_image(t_img *image);
//print_map.c
void	ft_print_image(t_fdf *fdf, t_list **lst);
void drawline(int x0, int y0, int x1, int y1, t_fdf *fdf);
//hooks.c
int	ft_key_press(int keycode, t_fdf *fdf);
#endif
