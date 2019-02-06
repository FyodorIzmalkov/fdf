/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/06 22:33:26 by lsandor-         ###   ########.fr       */
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
