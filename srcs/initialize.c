/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:54:43 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 16:25:52 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_iso_scale(t_fdf *fdf)
{
	double x;
	double y;
	
	x = sqrt(fdf->col * fdf->col + fdf->row * fdf->row - fdf->col * fdf->row);
	y = sqrt(fdf->col * fdf->col + fdf->row * fdf->row + fdf->col * fdf->row);
	y = fdf->options->z0 > y ? fdf->options->z0 + y : y;
	x = W_WIDTH / x * 0.9;
	y = W_HEIGHT / y * 0.9;
	fdf->options->iso_scale = x > y ? y : x;
}

void	ft_initialize_fdf(t_fdf *fdf)
{
	ft_display_error(!(fdf->options = ft_memalloc(sizeof(t_options))), MlcErr); 
	ft_display_error(!(fdf->image = ft_memalloc(sizeof(t_img))), MlcErr);
	fdf->options->min = 2147483647;
	fdf->options->max = -2147483648;
	fdf->options->z0 = 0.;
	fdf->col = -1;
	fdf->row = 0;
}

void	ft_initialize_map(t_fdf *fdf)
{
	fdf->options->z0 = fdf->options->max + ABS(fdf->options->min);
	fdf->options->x0 = fdf->col / 2;
	fdf->options->y0 = fdf->row / 2;
	ft_get_iso_scale(fdf);
}
