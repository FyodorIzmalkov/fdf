/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:36:26 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 19:49:30 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_dots(t_pixel *pixel, t_pixel angle, t_calc res, t_fdf *fdf)
{
	t_pixel prev;

	pixel->x -= fdf->options->x0;
	pixel->y -= fdf->options->y0;
	if (fdf->options->min >= 0)
		pixel->z -= fdf->options->z0 >> 1;
	prev.x = pixel->x;
	prev.z = pixel->z;

}
