/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:32:38 by vbrazas           #+#    #+#             */
/*   Updated: 2019/01/24 16:18:30 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	clear_output(char *tetri, char **output)
{
	int			y;
	int			x;
	int			z;

	y = 0;
	z = 0;
	while ((tetri[z] == '.' || tetri[z] == '\n') && tetri[z] != '\0')
		z++;
	while (output[y])
	{
		x = 0;
		while (output[y][x])
		{
			if (output[y][x] == tetri[z])
				output[y][x] = '.';
			x++;
		}
		y++;
	}
}
