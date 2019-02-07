/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:55:20 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 00:00:20 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawline(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			ft_set_color_to_image(fdf, x, y, 16777215);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			ft_set_color_to_image(fdf, x, y, 16777215);
			p=p+2*dy;
		}
		x=x+1;
	}
}

static void iso(double *x, double *y, double z)
{
    double previous_x;
    double previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_print_image(t_fdf *fdf, t_list **lst)
{
	t_list *next;
	t_pixel *pixel;
	
	next = *lst;
	while (next)
	{
		pixel = next->content;
		pixel->x *= 20;
		pixel->y *= 20;
		pixel->z *= 20;
		iso(&pixel->x, &pixel->y, pixel->z);
		ft_set_color_to_image(fdf, 400+ pixel->x, 400+pixel->y, 16777215);
		next = next->next;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->image->img_ptr, 0, 0);
}
