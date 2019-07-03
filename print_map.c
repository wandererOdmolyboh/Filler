/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:27:33 by vbrazas           #+#    #+#             */
/*   Updated: 2019/01/24 14:40:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **output)
{
	int	x;

	x = 0;
	while (output[x] != NULL)
	{
		ft_putstr(output[x]);
		ft_putchar('\n');
		x++;
	}
}
