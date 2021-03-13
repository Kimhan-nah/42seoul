/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:03:51 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/10 17:17:24 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	len;
	int		index;

	len = 0;
	index = 0;
	while (str[index++])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	copy_len;
	unsigned int	res;

	index = 0;
	dest_len = str_len(dest);
	src_len = str_len(src);
	if (dest_len > size)
		return (src_len + size);
	res = dest_len + src_len;
	if (dest_len < size)
	{
		copy_len = size - dest_len - 1;
		while (index < copy_len && src[index])
			dest[dest_len++] = src[index++];
		dest[dest_len] = '\0';
	}
	return (res);
}
