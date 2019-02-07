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
	return (0);
}
