/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:42:05 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 12:08:02 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*ptr;

	if (!lst || !new_node)
		exit(EXIT_FAILURE);
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new_node;
}
