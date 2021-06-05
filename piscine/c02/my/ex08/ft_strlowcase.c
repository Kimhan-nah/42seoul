/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:43:07 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/25 21:43:10 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 65 && str[index] <= 90)
			str[index] += 32;
		index++;
	}
	return (str);
}
