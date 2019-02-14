/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:27:19 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/14 23:03:21 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_decreaser(t_fdf *fdf)
{
	if (fdf->options->max > 10 && fdf->options->max < 100)
		fdf->decreaser = 2;
	else if (fdf->options->max >= 100 && fdf->options->max < 1000)
		fdf->decreaser = 10;
	else if (fdf->options->max >= 1000 && fdf->options->max < 10000)
		fdf->decreaser = 50;
}
