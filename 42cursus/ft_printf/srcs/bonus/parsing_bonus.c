/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:26:17 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:47:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	init_info(t_info *info)
{
	info->left_sort = 0;
	info->zero = 0;
	info->precision = -1;
	info->is_precision = 0;
	info->width = 0;
	info->error = 0;
	info->specifier = '0';
}

static void	(*is_specifier(char ptr))(t_info *info)
{
	if (ptr == 'c')
		return (specifier_c);
	if (ptr == 's')
		return (specifier_s);
	if (ptr == 'p')
		return (specifier_p);
	if (ptr == 'i' || ptr == 'd')
		return (specifier_id);
	if (ptr == 'u')
		return (specifier_u);
	if (ptr == 'x' || ptr == 'X')
		return (specifier_xX);
	if (ptr == '%')
		return (specifier);
	return (0);
}

static void	set_width(char **ptr, t_info *info)
{
	int	num;

	num = 0;
	if (**ptr == '*')
	{
		info->width = va_arg(info->ap, int);
		if (info->width < 0)
		{
			info->left_sort = 1;
			info->width *= -1;
		}
		return ;
	}
	while (ft_isdigit(**ptr))
	{
		num = num * 10 + **ptr - '0';
		(*ptr)++;
	}
	info->width = num;
	(*ptr)--;
}

static void	set_precision(char **ptr, t_info *info)
{
	int	num;

	num = 0;
	(*ptr)++;
	info->is_precision = 1;
	if (**ptr == '*')
	{
		info->precision = va_arg(info->ap, int);
		if (info->precision < 0)
			info->is_precision = 0;
		return ;
	}
	while (ft_isdigit(**ptr))
	{
		num = num * 10 + **ptr - '0';
		(*ptr)++;
	}
	info->precision = num;
	(*ptr)--;
}

void	parse(char **ptr, t_info *info)
{
	void	(*fp)();

	fp = is_specifier(**ptr);
	while (!fp)
	{
		if (**ptr == '-')
			info->left_sort = 1;
		else if (**ptr == '0')
			info->zero = 1;
		else if (**ptr == '*' || ft_isdigit(**ptr))
			set_width(ptr, info);
		else if (**ptr == '.')
			set_precision(ptr, info);
		(*ptr)++;
		fp = is_specifier(**ptr);
	}
	if ((fp != specifier && info->is_precision && info->width)
		|| info->left_sort)
		info->zero = 0;
	info->specifier = **ptr;
	fp(info);
	(*ptr)++;
}
