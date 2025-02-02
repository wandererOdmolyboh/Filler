/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:55:30 by vbrazas           #+#    #+#             */
/*   Updated: 2019/01/24 13:05:52 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			rename_line(char *line)
{
	int			i;
	char		a;

	a = 'A';
	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
			line[i] = a;
		if (line[i] == '\n' && line[i - 1] == '\n')
			a++;
		i++;
	}
}
