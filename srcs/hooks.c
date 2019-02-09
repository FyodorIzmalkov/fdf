/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:30:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/09 13:50:42 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_press(int keycode, t_fdf *fdf)
{
	ft_clear_image(fdf->image);
	keycode == 53 ? exit (0) : 0;
	if (keycode == 18)
		fdf->options->proection = 1;
	if (keycode == 19)
		fdf->options->proection = 2;
	if (keycode == 20)
		fdf->options->proection = 3;
	ft_print_map(*fdf);
	return (0);
}
