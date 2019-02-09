/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:30:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/09 15:16:52 by lsandor-         ###   ########.fr       */
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
}

int	ft_key_press(int keycode, t_fdf *fdf)
{
	ft_clear_image(fdf->image);
	keycode == 53 ? exit (0) : 0;
	keycode == 15 ? fdf->options->size *= 1.1 : 0;
	keycode == 3 ? fdf->options->size *= 0.9 : 0;
	if (keycode == 18)
	{
		ft_set_defaults(fdf);
		fdf->options->proection = 1;
	}
	if (keycode == 19)
	{
		ft_set_defaults(fdf);
		fdf->options->proection = 2;
	}
	if (keycode == 20)
	{
		ft_set_defaults(fdf);
		fdf->options->proection = 3;
	}
	ft_key_press2(keycode, fdf);
	ft_print_map(*fdf);
	return (0);
}
