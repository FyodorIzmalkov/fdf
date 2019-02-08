/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/08 19:27:38 by lsandor-         ###   ########.fr       */
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
