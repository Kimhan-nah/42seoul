/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:42:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/09/25 17:24:11 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	putnbr(char *str, unsigned int n, int idx)
{
	unsigned int	nbr;

	nbr = n;
	idx--;
	while (idx >= 0 && !str[idx])
	{
		str[idx] = nbr % 10 + '0';
		nbr /= 10;
		idx--;
	}
}

static char	*ft_uitoa(unsigned int n, t_info *info)
{
	char			*str;
	unsigned int	nbr;
	int				len;

	nbr = n;
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	str = (char *)ft_calloc(len + 2, sizeof(char));
	if (check_error(info, str))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
		putnbr(str, n, len);
	return (str);
}

void	specifier_u(t_info *info)
{
	char			*str;
	char			*tmp;
	unsigned int	num;
	int				len;

	num = va_arg(info->ap, unsigned int);
	str = ft_uitoa(num, info);
	if (!str)
		return ;
	tmp = str;
	len = ft_strlen(str);
	if (info->zero && info->width)
	{
		info->precision = info->width;
		info->is_precision = 2;
	}
	if (num < 0)
		negative_num(info, &str);
	str = str_with_precision(info, str, ft_strlen(str), num);
	free(tmp);
	if (!str)
		return ;
	print_u(info, str, ft_strlen(str));
	free(str);
}

void	specifier_id(t_info *info)
{
	char	*str;
	char	*tmp;
	int		num;

	num = va_arg(info->ap, int);
	str = ft_itoa(num);
	if (check_error(info, str))
		return ;
	tmp = str;
	if (info->zero && info->width)
	{
		info->precision = info->width;
		info->is_precision = 2;
	}
	if (num < 0)
		negative_num(info, &str);
	str = str_with_precision(info, str, ft_strlen(str), num);
	free(tmp);
	if (!str)
		return ;
	print_id(info, str, ft_strlen(str), num);
	free(str);
}
