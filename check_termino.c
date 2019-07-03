/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_termino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:40:11 by vbrazas           #+#    #+#             */
/*   Updated: 2019/01/24 12:46:19 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	count_hashtag(char *buf)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (buf[n])
	{
		if (buf[n] == '#' && buf[n + 1] == '#')
			i++;
		if (buf[n] == '#' && buf[n + 5] == '#')
			i++;
		n++;
	}
	return (i);
}

static	int	hard_val(char *buf)
{
	int		n;

	n = 0;
	while (buf[n] != '\0')
	{
		if (buf[n] == '#')
			break ;
		n++;
	}
	n = count_hashtag(buf);
	if (n == 3 || n == 4)
		return (0);
	return (5);
}

int			simple_val(char *buf)
{
	int		count;
	int		n;
	int		count_n;

	n = 0;
	count = 0;
	count_n = 0;
	while (buf[n] != '\0')
	{
		if (n % 5 != 4 && !(buf[n] == '#' || buf[n] == '.') && n < 20)
			return (2);
		else if (buf[n] != '\n' && n % 5 == 4)
			return (2);
		if (buf[n] == '\n')
			count_n++;
		if (buf[n] == '#')
			count++;
		n++;
	}
	if ((count_n != 5 && count_n != 4) || count != 4)
		return (6);
	return (hard_val(buf));
}
