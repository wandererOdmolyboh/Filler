/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:37:01 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 15:25:34 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	int	dopoln_main(char **argv, char *buf, char *line, int i)
{
	if (ft_strlen(buf) != 20 || (i < 1 || i > 26))
	{
		error_output(argv, line, buf, FALSE);
		return (-1);
	}
	fillit(line);
	return (0);
}

static	int	addone_main(char **argv, char *buf, int fd, char *line)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_output(argv, line, buf, TRUE);
	while ((count = read(fd, buf, 21)) > 19)
	{
		i++;
		buf[count] = '\0';
		if (simple_val(buf) != 0)
		{
			error_output(argv, line, buf, FALSE);
			return (-1);
		}
		tmp = line;
		line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (dopoln_main(argv, buf, line, i) == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	buf = NULL;
	line = NULL;
	if (argc == 2)
	{
		if ((buf = (char *)malloc(BUFF_SIZE + 1)) == NULL)
			return ((-1));
		addone_main(argv, buf, fd, line);
	}
	else
		error_output(argv, line, buf, TRUE);
	return (0);
}
