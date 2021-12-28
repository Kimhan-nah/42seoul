/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:12:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/09/25 17:24:15 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	hex_len(unsigned long long addr)
{
	int	len;

	len = 0;
	while (addr > 0)
	{
		len++;
		addr /= 16;
	}
	return (len);
}

static char	*convert_hex(t_info *info, unsigned long long addr)
{
	char	*hex;
	char	*str;
	int		index;

	hex = "0123456789abcdef";
	index = hex_len(addr) - 1;
	str = (char *)ft_calloc(sizeof(char), index + 2);
	if (check_error(info, str))
		return (0);
	while (index >= 0)
	{
		str[index] = hex[addr % 16];
		addr /= 16;
		index--;
	}
	return (str);
}

void	specifier_p(t_info *info)
{
	unsigned long long	addr;
	char				*str;

	addr = va_arg(info->ap, unsigned long long);
	if (addr == 0 && !info->is_precision)
	{
		print_p(info, "0", 1);
		return ;
	}
	str = convert_hex(info, addr);
	if (!str)
		return ;
	print_p(info, str, ft_strlen(str));
	free(str);
	str = 0;
}
