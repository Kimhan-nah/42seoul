/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:24:53 by hannkim           #+#    #+#             */
/*   Updated: 2021/03/18 23:09:20 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len_base(char *base)
{
	int	len;

	len = 0;
	while (*base)
	{
		len++;
		base++;
	}
	return (len);
}

int		is_valid_base(char *base, int b_len)
{
	char *ptr1;
	char *ptr2;

	ptr1 = base;
	ptr2 = base;
	if (b_len <= 1)
		return (0);
	while (*ptr1)
	{
		if (*ptr1 == '+' || *ptr1 == '-'
				|| (*ptr1 >= 9 && *ptr1 <= 13) || *ptr1 == 32)
			return (0);
		while (*ptr2)
		{
			if (*ptr1 == *ptr2 && ptr1 != ptr2)
				return (0);
			ptr2++;
		}
		ptr2 = base;
		ptr1++;
	}
	return (1);
}

int		is_valid_str(char *str, char *base, int *i, int *m_count)
{
	int	j;

	j = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			(*m_count) *= -1;
		(*i)++;
	}
	while (str[*i] != base[j] && base[j])
		j++;
	if (base[j] == '\0')
		return (0);
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int m_count;
	int i;
	int	j;
	int	res;

	i = 0;
	m_count = 1;
	res = 0;
	if (is_valid_str(str, base, &i, &m_count))
	{
		while (str[i])
		{
			j = 0;
			while (str[i] != base[j] && base[j])
				j++;
			if (base[j] == '\0')
				break ;
			res = res * len_base(base) + j;
			i++;
		}
	}
	return (m_count * res);
}
