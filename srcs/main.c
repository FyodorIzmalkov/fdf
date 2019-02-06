/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/06 22:35:51 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_list *lst;
//	t_map	*map;

	ft_display_error(argc != 2, "Error. Usage: ./fdf input_filename");
	return (0);
}
