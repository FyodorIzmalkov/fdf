/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/06 23:22:30 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_list *lst;
	t_fdf	fdf;

	ft_display_error(argc != 2, "Error. Usage: ./fdf filename");
	fd = open(argv[1], O_RDONLY);
	ft_display_error((fd < 0), "Error. Invalid file name.");
	ft_initialize_fdf(&fdf);
	ft_read_map(fd, &lst, &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, W_WIDTH, W_HEIGHT, argv[1]);
	ft_initialize_map(&fdf);
	ft_initialize_image(&fdf);
//	drawline(50, 50, 70, 70, &fdf);
	ft_print_image(&fdf, &lst);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
