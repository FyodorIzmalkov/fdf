/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:54:43 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 16:24:29 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_iso_scale(t_fdf *fdf)
{
}

void	ft_initialize_fdf(t_fdf *fdf)
{
	ft_display_error(!(fdf->options = ft_memalloc(sizeof(t_options))), 
			"Malloc allocation error.");
	fdf->options->min = 2147483647;
	fdf->options->max = -2147483648;
	fdf->options->z0 = 0.;
	fdf->col = -1;
	fdf->row = 0;
}

void	ft_initialize_map(t_fdf *fdf)
{
	fdf->options->z0 = fdf->options->max + ABS(fdf->options->min);
	fdf->x0 = fdf->col / 2;
	fdf->y0 = fdf->row / 2;
//	ft_get_iso_scale(fdf);
}
