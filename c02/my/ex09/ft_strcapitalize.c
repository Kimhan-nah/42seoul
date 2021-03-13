/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:40:50 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/06 21:37:04 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_flag(char c);
char	*ft_strcapitalize(char *str);

int		ft_flag(char c)
{
	int flag;

	flag = 0;
	if (c >= 32 && c <= 47)
		flag = 0;
	else if (c >= 58 && c <= 64)
		flag = 0;
	else if (c >= 91 && c <= 96)
		flag = 0;
	else if (c >= 123 && c <= 126)
		flag = 0;
	else if (c >= 'a' && c <= 'z')
		flag = 1;
	else if (c >= 'A' && c <= 'Z')
		flag = 2;
	else if (c >= '0' && c <= '9')
		flag = 3;
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int index;
	int flag;

	index = -1;
	flag = 0;
	while (str[++index] != '\0')
	{
		if (flag == 0)
		{
			flag = ft_flag(str[index]);
			if (flag == 1)
				str[index] -= 32;
		}
		else if (flag != 0)
		{
			flag = ft_flag(str[index]);
			if (flag == 2)
				str[index] += 32;
		}
	}
	return (str);
}
