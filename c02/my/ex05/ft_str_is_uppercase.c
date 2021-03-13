/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:42:30 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/25 21:42:33 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *(str + index);
	while (c != '\0')
	{
		if (c >= 65 && c <= 90)
			index++;
		else
			return (0);
		c = *(str + index);
	}
	return (1);
}
