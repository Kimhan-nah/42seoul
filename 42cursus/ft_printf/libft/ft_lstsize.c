/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:15:20 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 01:05:49 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*ptr;

	len = 0;
	ptr = lst;
	if (!lst)
		return (0);
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
