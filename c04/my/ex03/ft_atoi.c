/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:55:22 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/11 09:55:55 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_ch(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	else if (ch == '+')
		return (2);
	else if (ch == '-')
		return (3);
	else if (ch >= '0' && ch <= '9')
		return (4);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	char	*ptr;
	int		m_count;
	int		res;

	ptr = str;
	m_count = 1;
	res = 0;
	while (is_valid_ch(*ptr) == 1)
		ptr++;
	while (is_valid_ch(*ptr) == 2 || is_valid_ch(*ptr) == 3)
	{
		if (is_valid_ch(*ptr) == 3)
			m_count *= -1;
		ptr++;
	}
	while (is_valid_ch(*ptr) == 4)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	res = res * m_count;
	return (res);
}
