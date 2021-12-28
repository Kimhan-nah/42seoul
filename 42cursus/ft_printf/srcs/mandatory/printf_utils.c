/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:23:56 by hannkim           #+#    #+#             */
/*   Updated: 2021/09/25 17:24:02 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*str_with_precision(t_info *info, char *str, int len, int num)
{
	int		i;
	int		size;
	char	*new_str;

	i = 0;
	size = info->precision;
	if (len > info->precision)
		size = len;
	new_str = (char *)ft_calloc(size + 1, sizeof(char));
	if (check_error(info, new_str))
		return (0);
	if (!info->precision && !num)
	{
		new_str[0] = 0;
		return (new_str);
	}
	while (size > len)
	{
		new_str[i] = '0';
		i++;
		len++;
	}
	ft_strlcpy(&new_str[i], str, size + 1);
	return (new_str);
}

int	check_error(t_info *info, char *str)
{
	if (!str)
	{
		info->error = 1;
		return (1);
	}
	return (0);
}

void	negative_num(t_info *info, char **str)
{
	(*str)++;
	if (info->is_precision == 2)
		info->precision--;
	info->width--;
}

void	specifier(t_info *info)
{
	char	c;

	c = ' ';
	if (info->zero)
		c = '0';
	if (info->left_sort)
	{
		write(1, "%", 1);
		info->ret++;
	}
	while (info->width > 1)
	{
		write(1, &c, 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, "%", 1);
		info->ret++;
	}
}
