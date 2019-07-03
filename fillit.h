/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:46:10 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/24 16:22:46 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 21
# define TRUE 1
# define FALSE 0
# define TERMINO point_point->head->content
# define REZULT point_point->output

typedef	struct			s_tetrimin
{
	char				*content;
	size_t				content_size;
	struct s_tetrimin	*next;
	struct s_tetrimin	*prev;
}						t_tetri;

typedef struct			s_counter
{
	t_tetri				*head;
	char				**output;
}						t_pointers;

void					*ft_bzero(void *s1, size_t n);
int						ft_isalpha(int n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strdup(const char *src);
size_t					ft_strlen(const char *str);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					*ft_memset(void *b, int c, size_t len);

int						simple_val(char *buf);
void					error_output(char **argv, char *line, char *buf,
						int ch);
void					rename_line(char *line);
void					fillit(char *line);
char					pointer(int i, t_tetri *head);
void					print_map(char **output);
void					clear_output(char *tetri, char **output);
int						recursive(t_tetri *head, char **output);
int						try_add_ter(t_pointers *point_point, int y,
						int x, int z);

#endif
