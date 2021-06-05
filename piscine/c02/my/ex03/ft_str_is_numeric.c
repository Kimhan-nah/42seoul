/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:41:52 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/25 21:42:14 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *(str + index);
	while (c != '\0')
	{
		if (c >= 48 && c <= 57)
			index++;
		else
			return (0);
		c = *(str + index);
	}
	return (1);
}
