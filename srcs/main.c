/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/06 21:33:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "error_message.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;
	t_list *lst;
	t_map	*map;

	ft_display_error(argc != 2, "error: input only one filename");
	return (0);
}
