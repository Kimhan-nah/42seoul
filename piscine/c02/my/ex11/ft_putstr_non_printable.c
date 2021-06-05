/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:40:08 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/06 22:43:51 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_putchar(char c);
void	ft_str_to_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 32 && str[index] <= 126)
			ft_putchar(str[index]);
		else
		{
			ft_str_to_hex(str[index]);
		}
		index++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_str_to_hex(char c)
{
	char *hex;

	hex = "0123456789abcdef";
	ft_putchar('/');
	ft_putchar(hex[(unsigned char)c / 16]);
	ft_putchar(hex[(unsigned char)c % 16]);
}
