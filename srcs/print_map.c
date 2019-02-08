/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:55:20 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 20:25:07 by lsandor-         ###   ########.fr       */
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
			ft_set_pixel_to_image(fdf, x, y, 16777215);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			ft_set_pixel_to_image(fdf, x, y, 16777215);
			p=p+2*dy;
		}
		x=x+1;
	}
}

static void	ft_set_color(t_fdf *fdf)
{
	double third;

	third = fdf->options->z0 / 3;
	if (fdf->first.z < 0)
		fdf->first.color = 0x4C2908;
	else if (fdf->first.z <= third)
		fdf->first.color = 0xDB4A4A;
	else if (fdf->first.z <= third * 2)
		fdf->first.color = 0xD67022;
	else if (fdf->first.z <= fdf->options->z0)
		fdf->first.color = 0xE5D120;
	if (fdf->second.z < 0)
		fdf->second.color = 0x4C2908;
	else if (fdf->second.z <= third)
		fdf->second.color = 0xDB4A4A;
	else if (fdf->second.z <= third * 2)
		fdf->second.color = 0xD67022;
	else if (fdf->second.z <= fdf->options->z0)
		fdf->second.color = 0xE5D120;
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

void	ft_print_map(t_fdf fdf)
{
	ft_calculate_angles(&fdf);
	while (fdf.lines)
	{
		fdf.first = *((t_line *)fdf.lines->content)->a;
		fdf.second = *((t_line *)fdf.lines->content)->b;
		ft_set_color(&fdf);
		ft_rotate_dots(&fdf.first, fdf.res,  &fdf);
		ft_rotate_dots(&fdf.second, fdf.res, &fdf);
		fdf.lines = fdf.lines->next;
	}

}
