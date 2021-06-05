/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:03:45 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/11 21:13:52 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		s_index;
	int		f_index;
	char	*res;

	s_index = 0;
	if (*to_find == 0)
		return (str);
	while (str[s_index])
	{
		res = &str[s_index];
		f_index = 0;
		while (str[s_index + f_index] == to_find[f_index] && str[s_index + f_index])
			f_index++;
		if (to_find[f_index] == '\0')
			return (res);
		s_index++;
	}
	res = 0;
	return (res);
}
