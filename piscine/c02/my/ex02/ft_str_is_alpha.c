/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:04:01 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/07 23:15:42 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *(str + index);
	while (c != '\0')
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			index++;
		else
			return (0);
		c = *(str + index);
	}
	return (1);
}
