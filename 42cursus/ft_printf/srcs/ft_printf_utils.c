/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:47:14 by hannkim           #+#    #+#             */
/*   Updated: 2021/06/11 14:12:18 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


// ops c & s
void	print_str()
{

}

// ops p
void	print_addr(void *addr)
{
	char		arr[16];
	char		*hex;
	long long	ad;
	int			index;

	hex = "0123456789abcdef";
	ad = (long long)addr;
	index = 15;
	while (index >= 0)
	{
		arr[index] = hex[ad % 16];
		ad /= 16;
		index--;
	}
	index = 0;
	while (index < 16)
	{
		write(1, &arr[index], 1);
		index++;
	}
}

// ops d & i
void	print_int()
{

}


// ops u
void	print_u()
{

}


// ops xX
void	print_xX()
{

}
