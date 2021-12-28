/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:26:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:47:41 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static void	print_num(t_info *info, char *str, int len, int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		info->ret++;
	}
	write(1, str, len);
	info->ret += len;
}

void	print_id(t_info *info, char *str, int len, int num)
{
	char	c;

	c = ' ';
	if (info->zero)
		c = '0';
	if (info->left_sort)
		print_num(info, str, len, num);
	while (info->width > len)
	{
		write(1, &c, 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
		print_num(info, str, len, num);
}

void	print_u(t_info *info, char *str, int len)
{
	char	c;

	c = ' ';
	if (info->zero)
		c = '0';
	if (info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
	while (info->width > len)
	{
		write(1, &c, 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
}

void	print_p(t_info *info, char *str, int len)
{
	if (info->left_sort)
	{
		write(1, "0x", 2);
		write(1, str, len);
		info->ret += len + 2;
	}
	while (info->width > len + 2)
	{
		write(1, " ", 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, "0x", 2);
		write(1, str, len);
		info->ret += len + 2;
	}
}

void	print_xX(t_info *info, char *str, int len)
{
	char	c;

	c = ' ';
	if (info->zero)
		c = '0';
	if (info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
	while (info->width > len)
	{
		write(1, &c, 1);
		info->width--;
		info->ret++;
	}
	if (!info->left_sort)
	{
		write(1, str, len);
		info->ret += len;
	}
}
