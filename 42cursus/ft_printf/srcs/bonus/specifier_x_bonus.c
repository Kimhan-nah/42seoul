/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:27:06 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:48:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static char	*convert_hex(t_info *info, unsigned int num)
{
	char	*hex;
	char	*str;
	int		index;

	if (info->specifier == 'x')
		hex = "0123456789abcdef";
	else if (info->specifier == 'X')
		hex = "0123456789ABCDEF";
	if (num == 0)
		return (ft_strdup("0"));
	index = hex_len(num) - 1;
	if (index < info->precision)
		index = info->precision - 1;
	str = (char *)ft_calloc(sizeof(char), index + 2);
	if (check_error(info, str))
		return (0);
	while (index >= 0)
	{
		str[index] = hex[num % 16];
		num /= 16;
		index--;
	}
	return (str);
}

void	specifier_xX(t_info *info)
{
	char			*str;
	char			*tmp;
	unsigned int	num;

	num = va_arg(info->ap, unsigned int);
	str = convert_hex(info, num);
	if (!str)
		return ;
	tmp = str;
	if (info->zero && info->width)
	{
		info->precision = info->width;
		info->is_precision = 0;
	}
	str = str_with_precision(info, str, ft_strlen(str), num);
	free(tmp);
	tmp = 0;
	if (!str)
		return ;
	print_xX(info, str, ft_strlen(str));
	free(str);
}
