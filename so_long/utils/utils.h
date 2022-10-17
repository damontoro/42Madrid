/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:11:18 by dmontoro          #+#    #+#             */
/*   Updated: 2022/10/08 11:09:15 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include"../libs/libft/libft.h"
# include"../types.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef MAP_CHARS
#  define MAP_CHARS "10CEPX"
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strchr_gnl(const char *s, int c);

void	ft_error(const char *str);

#endif