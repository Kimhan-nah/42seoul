/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:41:18 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/25 21:42:21 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *(str + index);
	while (c != '\0')
	{
		if (c >= 97 && c <= 122)
			index++;
		else
			return (0);
		c = *(str + index);
	}
	return (1);
}
