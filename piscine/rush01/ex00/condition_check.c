/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esim <esim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:34:12 by esim              #+#    #+#             */
/*   Updated: 2021/03/07 20:00:51 by esim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			**g_condition;
extern int	g_size;
int			init_board(void);

int			is_space_or_null(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else if (c == 0)
		return (2);
	else
		return (0);
}

char		*ft_delete_space(char *str)
{
	while (is_space_or_null(*str) == 1)
		str++;
	return (str);
}

int			is_vnum(char c)
{
	return (c >= '1' && c <= (g_size + '0'));
}

int			make_condition(int cond_x, int cond_y, int *cnt, char *str)
{
	int i;

	i = -1;
	g_condition = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4)
		g_condition[i] = (int *)malloc(sizeof(int) * g_size);
	while (*str)
	{
		str = ft_delete_space(str);
		if (*str == 0)
			break ;
		if (is_vnum(*str) && is_space_or_null(*(str + 1)) && *cnt < 4 * g_size)
			g_condition[cond_x][cond_y++] = *str - '0';
		else
			return (0);
		(*cnt)++;
		cond_x = (cond_y == g_size) ? cond_x + 1 : cond_x;
		cond_y = (cond_y == g_size) ? 0 : cond_y;
		str++;
	}
	return (1);
}

int			is_valid(char *str)
{
	int count;
	int cond_x;
	int cond_y;

	cond_x = 0;
	cond_y = 0;
	count = 0;
	if (!make_condition(cond_x, cond_y, &count, str))
		return (0);
	if (count < 4 * g_size)
		return (0);
	if (!init_board())
		return (0);
	return (1);
}
