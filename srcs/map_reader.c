/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 23:22:38 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 18:42:58 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_read_color(char *str, t_fdf *fdf)
{
	int color;

	color = 0xFFFFFF;
	if (str)
	{
		color = ft_atoi_base(++str, 16);
		fdf->options->coloured = 1;
	}
	return (color);
}

static	void	ft_save_coordinats(char **args, t_list **lst, int y, t_fdf *fdf)
{
	int x;
	t_pixel pixel;
	t_list *tmp;
	size_t struct_size;

	struct_size = sizeof(t_pixel);
	x = -1;
	while (args[++x])
	{
		pixel.x = x;
		pixel.y = y;
		pixel.z = ft_atoi(args[x]);
		if (pixel.z > fdf->options->max)
			fdf->options->max = pixel.z;
		if (pixel.z < fdf->options->min)
			fdf->options->min = pixel.z;
		pixel.color = ft_read_color(ft_strchr(args[x], ','), fdf);
		ft_display_error(!(tmp = ft_lstnew(&pixel, struct_size)), MlcErr);
		ft_lstadd(lst, tmp);
	}
}

static	int	ft_count_width(char **line_args)
{
	int i;

	while (line_args[i])
		i++;
	return (i);
}

void	ft_read_map(int fd, t_list **lst, t_fdf *fdf)
{
	char *gnl;
	char **line_args;

	while (get_next_line(fd, &gnl) > 0)
	{
		ft_display_error(!(line_args = ft_strsplit(gnl, ' ')), MlcErr);
		if (fdf->col == -1)
			fdf->col = ft_count_width(line_args);
		ft_display_error((fdf->col != ft_count_width(line_args)), MapError);
		ft_save_coordinats(line_args, lst, fdf->row, fdf);
		ft_free_args(&line_args, fdf->col);
		fdf->row++;
	}
}
