/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:30:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/13 19:11:19 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static	void	ft_key_press2(int keycode, t_fdf *fdf)
{
	keycode == 13 ? fdf->angle.x -= 0.0698132 : 0;
	keycode == 1 ? fdf->angle.x += 0.0698132 : 0;
	keycode == 2 ? fdf->angle.y -= 0.0698132 : 0;
	keycode == 0 ? fdf->angle.y += 0.0698132 : 0;
	keycode == 14 ? fdf->angle.z -= 0.0698132 : 0;
	keycode == 12 ? fdf->angle.z += 0.0698132 : 0;
	keycode == 126 ? fdf->options->vertic -= 20 : 0;
	keycode == 125 ? fdf->options->vertic += 20 : 0;
	keycode == 123 ? fdf->options->horiz -= 20 : 0;
	keycode == 124 ? fdf->options->horiz += 20 : 0;
	if (keycode == 6)
	{
		fdf->options->x *= 0.9;
		if (fdf->options->x < fdf->options->z0)
			fdf->options->x = fdf->options->z0;
		if (fdf->options->x < fdf->col || fdf->options->x < fdf->row)
			fdf->options->x = fdf->col > fdf->row ? fdf->col : fdf->row;
	}
	keycode == 7 ? fdf->options->x *= 1.1 : 0;
	keycode == 69 ? fdf->options->altitude += 10 : 0;
	keycode == 78 ? fdf->options->altitude -= 10 : 0;
}

int	ft_key_press(int keycode, t_fdf *fdf)
{
	ft_clear_image(fdf->image);
	keycode == 53 ? exit (0) : 0;
	keycode == 15 ? fdf->options->size *= 1.1 : 0;
	keycode == 3 ? fdf->options->size *= 0.9 : 0;
	if (keycode >= 18 && keycode <= 21)
	{
		ft_set_defaults(fdf);
		keycode == 18 ? fdf->options->proection = 1 : 0;
		keycode == 19 ? fdf->options->proection = 2 : 0;
		keycode == 20 ? fdf->options->proection = 3 : 0;
		keycode == 21 ? fdf->options->proection = 4 : 0;
	}
	ft_key_press2(keycode, fdf);
	ft_print_map(*fdf);
	return (0);
}
