/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:54:43 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 14:11:35 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initialize_fdf(t_fdf *fdf)
{
	ft_display_error(!(fdf->options = ft_memmaloc(sizeof(t_options))), 
			"Malloc allocation error.");
	fdf->options->min = 2147483647;
	fdf->options->max = -2147483648;
	col = -1;
	row = 0;
}
