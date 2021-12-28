/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:26:01 by hannkim           #+#    #+#             */
/*   Updated: 2021/10/02 18:46:46 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static void	start_parsing(t_info *info, char **ptr)
{
	(*ptr)++;
	init_info(info);
	parse(ptr, info);
	if (info->error)
		info->ret = -1;
}

int	ft_printf(const char *format, ...)
{
	char	*ptr;
	char	*str;
	t_info	info;

	if (!format)
		return (-1);
	ptr = (char *)format;
	str = NULL;
	va_start(info.ap, format);
	info.ret = 0;
	info.error = 0;
	while (*ptr && !info.error)
	{
		if (*ptr == '%')
			start_parsing(&info, &ptr);
		else
		{
			write(1, ptr, 1);
			ptr++;
			info.ret++;
		}
	}
	va_end(info.ap);
	return (info.ret);
}
