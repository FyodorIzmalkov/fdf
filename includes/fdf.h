/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 14:11:17 by lsandor-         ###   ########.fr       */
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
# define MlcErr "Error. Malloc alocation failed."
# define MapError "Error. Map is invalid."

typedef struct s_pixel
{
	double x;
	double y;
	double z;
	int color;
}				t_pixel;

typedef struct	s_options
{
	int max;
	int min;
}				t_options;

typedef struct	s_fdf
{
	int	col;
	int row;
	t_options *options;
}				t_fdf;


// utilities.c
void	ft_display_error(int condition, char *str);
// initialize.c
void	ft_initialize_fdf(t_fdf *fdf);
// map_reader.c
void	ft_read_map(int fd, t_list **lst, t_fdf *fdf);
#endif
