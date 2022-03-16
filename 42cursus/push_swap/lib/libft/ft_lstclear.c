/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:21:22 by hannkim           #+#    #+#             */
/*   Updated: 2021/05/14 01:36:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	ptr = *lst;
	tmp = ptr;
	while (ptr)
	{
		tmp = tmp->next;
		del(ptr->content);
		free(ptr);
		ptr = tmp;
	}
	ptr = 0;
	*lst = 0;
}
