/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:03:36 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/09 10:03:38 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_index;
	unsigned int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index])
		dest_index++;
	while (src_index < nb && src[src_index])
	{
		dest[dest_index++] = src[src_index++];
	}
	dest[dest_index] = '\0';
	return (dest);
}
