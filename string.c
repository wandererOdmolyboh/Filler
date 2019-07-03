/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:36:29 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 15:11:33 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_sqrt(int tetri)
{
	int			i;

	i = 0;
	if (tetri < 5)
	{
		if (tetri == 1)
			i = 2;
		else if (tetri == 2)
			i = 3;
		else
			i = 4;
		return (i);
	}
	tetri *= 4;
	while (i < tetri)
	{
		if ((i * i) >= tetri)
			return (i);
		i++;
	}
	return (0);
}

static t_tetri	*listnew(void)
{
	t_tetri		*new;

	new = (t_tetri *)malloc(sizeof(t_tetri));
	new->content = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static	void	ft_create_elem(t_tetri **list)
{
	t_tetri		*line_tetri;

	line_tetri = listnew();
	line_tetri->prev = *list;
	(*list)->next = line_tetri;
	*list = (*list)->next;
}

void			fillit(char *line)
{
	t_tetri		*list;
	t_tetri		*head;
	int			tetri;
	char		*temp;

	tetri = 0;
	rename_line(line);
	list = listnew();
	head = list;
	while (line && line[0] != '\0')
	{
		temp = line;
		list->content = ft_strsub(temp, 0, 20);
		if (line[20] == '\0')
			line = ft_strsub(temp, 20, ft_strlen(line));
		else
		{
			ft_create_elem(&list);
			line = ft_strsub(temp, 21, ft_strlen(line));
		}
		free(temp);
		tetri++;
	}
	tetri = ft_sqrt(tetri);
	pointer(tetri, head);
}
