/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/14 20:38:40 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_error(int condition, char *str)
{
	if (condition)
	{
		ft_putendl(str);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_args(char ***args, int i)
{
	while (i--)
	{
		free(args[0][i]);
		args[0][i] = NULL;
	}
	free(args[0]);
	args[0] = NULL;
}

void	ft_calculate_angles(t_fdf *fdf)
{
	fdf->res.sinx = sin(fdf->angle.x);
	fdf->res.cosx = cos(fdf->angle.x);
	fdf->res.siny = sin(fdf->angle.y);
	fdf->res.cosy = cos(fdf->angle.y);
	fdf->res.sinz = sin(fdf->angle.z);
	fdf->res.cosz = cos(fdf->angle.z);
}

int	ft_red_cross(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	ft_draw_with_rmb(int x, int y, t_fdf *fdf)
{
	t_line dat;
	t_pixel f;
	t_pixel s;
	t_list *temp;

	fdf->mouse.draw_button = 0;
	f.x = fdf->mouse.x1;
	f.y = fdf->mouse.y1;
	f.color = 0xFFFFFF;
	s.x = x;
	s.y = y;
	s.color = 0xFFFFFF;
	dat.a = &f;
	dat.b = &s;
	printf("dat.a: %f %f, dat.b: %f %f\n", dat.a->x, dat.a->y, dat.b->x, dat.b->y);
	ft_display_error(!(temp = ft_lstnew(&dat, sizeof(t_line))),
			"Error. Malloc allocation failed.");
	ft_lstadd(&fdf->drawn, temp);
}
