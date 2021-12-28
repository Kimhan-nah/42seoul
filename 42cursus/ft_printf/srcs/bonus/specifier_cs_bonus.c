/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_cs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:26:41 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:47:54 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static void	print_s(t_info *info, char *str, int len)
{
	if (info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
	while (info->width > len)
	{
		write(1, " ", 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
}

void	specifier_s(t_info *info)
{
	char	*str;
	int		len;

	str = va_arg(info->ap, char *);
	len = 6;
	if (!str)
		str = "(null)";
	else
		len = ft_strlen(str);
	if (info->is_precision && info->precision < len)
		len = info->precision;
	print_s(info, str, len);
}

void	specifier_c(t_info *info)
{
	char	c;

	c = va_arg(info->ap, int);
	if (info->left_sort)
	{
		write(1, &c, 1);
		info->ret++;
	}
	while (info->width > 1)
	{
		write(1, " ", 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, &c, 1);
		info->ret++;
	}
}
