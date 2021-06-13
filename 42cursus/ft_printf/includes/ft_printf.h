/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:33:40 by hannkim           #+#    #+#             */
/*   Updated: 2021/06/13 16:36:04 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*
 * printf("%[flag][width][.precisionn][length]specifier", ...);
 */

typedef struct s_info {	
	int	left_sort;	// left : 1, no : 0
	int	zero_padding;	// if sort == 0 -> zero = 1;

	int	precision;
	int width;

} t_info;

#endif
