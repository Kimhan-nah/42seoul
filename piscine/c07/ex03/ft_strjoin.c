/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 02:48:51 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/16 12:24:20 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		str_len(int size, char **str, char *sep)
{
	int	ret_len;
	int sep_len;
	int i;
	int j;

	ret_len = 0;
	sep_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j++])
			ret_len++;
		i++;
	}
	while (*sep)
	{
		sep_len++;
		sep++;
	}
	ret_len += (size - 1) * sep_len;
	return (ret_len);
}

char	*ft_strcat(char *str, char *ret, int *r_idx)
{
	int	j;

	j = 0;
	while (str[j])
	{
		ret[*r_idx] = str[j];
		(*r_idx)++;
		j++;
	}
	return (ret);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char 	*ret;
	int		ret_len;
	int		i;
	int		r_idx;

	if (!size)
	{
		ret = (char *)malloc(1);
		ret[0] = 0;
		return (ret);
	}
	ret_len = str_len(size, str, sep);
	i = 0;
	r_idx = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ret_len)))		// exception check ( ret == 0 ) -> return ??
		return (0);
	while (i < size)
	{
		ret = ft_strcat(str[i], ret, &r_idx);
		if (i < size - 1)
			ret = ft_strcat(sep, ret, &r_idx);
		i++;
	}
	return (ret);
}

int	main(void)
{
	char **str;

	str = (char **)malloc(sizeof(char *) * 3);
	str[0] = "hello";
	str[1] = "bye";
	str[2] = "world";

	printf("%s", ft_strjoin(0, str, ",. /"));		// nothing?
	printf("%s\n", ft_strjoin(3, str, ",. /"));
	return 0;
}
