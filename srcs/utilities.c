/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 14:09:12 by lsandor-         ###   ########.fr       */
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
