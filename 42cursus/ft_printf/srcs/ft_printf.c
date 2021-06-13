/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:01:28 by hannkim           #+#    #+#             */
/*   Updated: 2021/06/13 17:40:47 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

// ft_printf("%[flag][width][.precision]specifier", ...);

void	set_flags(t_info *flags, va_list ap)
{

}

int		is_specifier(char ptr)
{
	if (ptr == 'c' || ptr == 's')
		return (1);
	if (ptr == 'p')
		return (2);
	if (ptr == 'i' || ptr == 'd')
		return (3);
	if (ptr == 'u')
		return (4);
	if (ptr == 'x' || ptr == 'X')
		return (5);
	return (0);
}

void	parse(char **ptr, va_list ap)
{
	t_info flags;

	if (**ptr == '%')
	{
		write(1, *ptr, 1);
		return ;
	}
	set_flags(&flags, ap);			// set flags and options
	if (is_specifier(**ptr))
	{
		// check flags and options, then 가변인자 처리
		
	}
	else
	{
		//error 
	}
}

int	ft_printf(const char *format, ...)
{
	char	*ptr;
	int		ret;
	va_list	ap; 

	ptr = (char *)format;
	va_start(ap, format);
	ret = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			parse(&ptr, ap);
		}
		else
		{
			write(1, ptr, 1);
			ptr++;
		}
	}
	va_end(ap);
	return (ret);
}

int main()
{
//	printf("%d\n", ft_printf("hello world\n"));
	ft_printf("it's %d\n", 42);

	return 0;
}
