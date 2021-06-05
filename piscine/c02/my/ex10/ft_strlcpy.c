/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:38:25 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/11 14:07:37 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	src_len;

	index = 0;
	src_len = ft_strlen(src);
	while (index < src_len && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (src_len);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
