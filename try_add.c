/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:22:18 by vbrazas           #+#    #+#             */
/*   Updated: 2019/01/24 14:40:25 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		addone_try(t_pointers *point_point, int y, int x, int z)
{
	if (TERMINO[z] && TERMINO[z + 4] &&
	(TERMINO[z + 4] == TERMINO[z]) && z + 4 < 22)
	{
		if (try_add_ter(point_point, y + 1, x - 1, z + 4) == -1)
			return (-1);
	}
	else if (TERMINO[z] && TERMINO[z + 5] &&
	(TERMINO[z + 5] == TERMINO[z]) && z + 5 < 22)
	{
		if (try_add_ter(point_point, y + 1, x, z + 5) == -1)
			return (-1);
	}
	return (0);
}

int				try_add_ter(t_pointers *point_point, int y, int x, int z)
{
	if (!REZULT[y] || !REZULT[y][x] || REZULT[y][x] != '.' ||
	REZULT[y][x] == '\0')
		return (-1);
	else if (ft_isalpha(REZULT[y][x]) || x < 0)
		return (-1);
	else if (TERMINO[z] && TERMINO[z + 1] &&
	(TERMINO[z + 1] == TERMINO[z]) && z + 1 < 22)
	{
		if (try_add_ter(point_point, y, x + 1, z + 1) == -1)
			return (-1);
	}
	else if (TERMINO[z] && TERMINO[z + 3] &&
	(TERMINO[z + 3] == TERMINO[z]) && z + 3 < 22)
	{
		if (try_add_ter(point_point, y + 1, x - 2, z + 3) == -1)
			return (-1);
	}
	else
		return (addone_try(point_point, y, x, z));
	return (0);
}
