/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:10:50 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 16:59:25 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	void	delete_output(char **output)
{
	int			x;

	x = 0;
	while (output[x])
	{
		free(output[x]);
		x++;
	}
	free(output);
	output = NULL;
}

static	void	delete_head(t_tetri *head)
{
	t_tetri		*head_swap;

	while (head != NULL)
	{
		head_swap = head->next;
		if (head)
		{
			free(head->content);
			free(head);
		}
		head = head_swap;
	}
	free(head);
	head = NULL;
}

char			pointer(int i, t_tetri *head)
{
	char		**output;
	int			x;

	x = 0;
	output = (char**)malloc(sizeof(char*) * (i + 1));
	while (i > x)
	{
		output[x] = (char*)malloc(sizeof(char) * (i + 1));
		output[x][i] = '\0';
		output[x] = ft_memset(output[x], '.', i);
		x++;
	}
	output[x] = NULL;
	if (recursive(head, output) == 0)
	{
		delete_output(output);
		pointer(i + 1, head);
	}
	else
	{
		print_map(output);
		delete_head(head);
		delete_output(output);
	}
	return (0);
}
