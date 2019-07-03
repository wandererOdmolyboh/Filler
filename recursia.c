/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:17:05 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 15:26:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	void	add_ter(t_pointers *point_point, int y, int x, int z)
{
	if (z < 20)
		REZULT[y][x] = TERMINO[z];
	if ((TERMINO[z + 1] == TERMINO[z]) && TERMINO[z + 1])
		add_ter(point_point, y, x + 1, z + 1);
	else if ((TERMINO[z + 3] == TERMINO[z]) && TERMINO[z + 3])
		add_ter(point_point, y + 1, x - 2, z + 3);
	else if ((TERMINO[z + 4] == TERMINO[z]) && TERMINO[z + 4])
		add_ter(point_point, y + 1, x - 1, z + 4);
	else if ((TERMINO[z + 5] == TERMINO[z]) && TERMINO[z + 5])
		add_ter(point_point, y + 1, x, z + 5);
}

static	int		addone_recursive(t_pointers *point_point, int y, int z)
{
	int x;

	while (REZULT[y] != NULL)
	{
		x = 0;
		while (REZULT[y][x] != '\0')
		{
			if (REZULT[y][x] == '.'
			&& (try_add_ter(point_point, y, x, z)) == 0)
			{
				add_ter(point_point, y, x, z);
				if (recursive(point_point->head->next, REZULT) == 1)
					return (1);
				else
					clear_output(point_point->head->content, REZULT);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				recursive(t_tetri *head, char **output)
{
	int			y;
	int			z;
	t_pointers	*point_point;

	if (head == NULL)
		return (1);
	point_point = (t_pointers*)malloc(sizeof(t_pointers));
	y = 0;
	z = 0;
	point_point->head = head;
	point_point->output = output;
	while (head && !ft_isalpha(head->content[z]))
		z++;
	if (addone_recursive(point_point, y, z) == 1)
	{
		free(point_point);
		return (1);
	}
	free(point_point);
	return (0);
}
