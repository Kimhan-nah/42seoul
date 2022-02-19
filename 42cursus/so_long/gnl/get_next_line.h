/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:47:21 by hannkim           #+#    #+#             */
/*   Updated: 2021/06/05 21:11:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>
# include <unistd.h>

extern int		get_next_line(int fd, char **line);
extern size_t	ft_strlen(const char *s);
extern char		*ft_strdup(const char *s1);
extern char		*ft_strchr(const char *s, int c);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
