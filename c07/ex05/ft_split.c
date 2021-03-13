/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 02:54:28 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/12 04:04:26 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int	str_len(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_flag(char ch, char *charset)
{
	int flag;
	int	i;

	flag = 0;
	i = 0;
	while (charset[i])
	{
		if (ch == charset[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}

int	count_word(char *str, char *charset)
{
	int	s_idx;
	int	c_idx;
	int	count;
	int	flag;

	s_idx = 0;
	count = 0;
	flag = 0;
	while (str[s_idx])
	{
		c_idx = 0;
		while (charset[c_idx])
		{

			
			c_idx++;
		}
		if (str[s_idx] == charset[c_idx] && st)
			printf("count:%d/charset:%c/str:%c\n", ++count, charset[c_idx], str[s_idx]);
		s_idx++;
	}
	return (count);
}

char **ft_split(char *str, char *charset)
{
	char	**p;
	int		len;

	len = str_len(str);
	count_word(str, charset);
}

int main()
{
	char *str = "Hello, world. bye";
	char *charset = ",. /";

	//ft_split(str, charset);
	count_word(str, charset);

	return (0);
}
