/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:33:40 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:39:44 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_info
{
	va_list	ap;
	int		ret;

	int		left_sort;
	int		zero;
	int		precision;
	int		is_precision;
	int		width;
	int		error;
	char	specifier;
}	t_info;

int		ft_printf(const char *format, ...);

void	init_info(t_info *info);
void	parse(char **ptr, t_info *info);

void	specifier_c(t_info *info);
void	specifier_s(t_info *info);
void	specifier_p(t_info *info);
void	specifier_id(t_info *info);
void	specifier_u(t_info *info);
void	specifier_xX(t_info *info);
void	specifier(t_info *info);

char	*str_with_precision(t_info *info, char *str, int len, int num);
int		check_error(t_info *info, char *str);
void	negative_num(t_info *info, char **str);

void	print_id(t_info *info, char *str, int len, int num);
void	print_u(t_info *info, char *str, int len);
void	print_p(t_info *info, char *str, int len);
void	print_xX(t_info *info, char *str, int len);

#endif
#endif
