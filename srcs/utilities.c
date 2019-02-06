/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/06 20:50:18 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_display_error(int condition, char *str)
{
	if (condition)
	{
		ft_putendl(str);
		exit(EXIT_FAILURE);
	}
}
