/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:42:42 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/25 23:44:17 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *(str + index);
	while (c != '\0')
	{
		if (c >= 32 && c <= 126)
			index++;
		else
			return (0);
		c = *(str + index);
	}
	return (1);
}
