/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:25:18 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 16:52:50 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_output(char **argv, char *line, char *buf, int ch)
{
	if (!ch)
	{
		if (line != NULL)
			free(line);
		if (buf != NULL)
			free(buf);
		ft_putstr("error\n");
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
}
