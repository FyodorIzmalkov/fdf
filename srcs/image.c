/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:25:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 16:49:04 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initialize_image(t_fdf *fdf)
{
	fdf->image->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
	fdf->image->add_ptr = mlx_get_data_addr(fdf->image->img_ptr, 
			&fdf->image->bpp, &fdf->image->size_line, &fdf->image->endian);
}
