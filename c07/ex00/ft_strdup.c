/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:17:29 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/12 02:48:31 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		src_len(char *src)
{
	int len;

	len = 0;
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		len;
	int		i;

	len = src_len(src);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (src[++i])
		ret[i] = src[i];
	ret[i] = '\0';
	return (ret);
}
