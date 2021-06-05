/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:03:30 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/09 10:03:31 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int dest_index;
	int src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index])
		dest_index++;
	while (src[src_index])
	{
		dest[dest_index++] = src[src_index++];	
	}
	dest[dest_index] = '\0';
	return (dest);
}
