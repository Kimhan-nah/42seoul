/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly-circular-linked-list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:18:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 19:21:55 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstadd_back(t_list **head, t_list *new_list)
{

	if (*head == 0)
	{
		printf("here\n");
		*head = new_list;
		new_list->next = new_list;
		new_list->prev = new_list;
		return ;
	}
	new_list->prev = (*head)->prev;
	new_list->next = *head;
	(*head)->prev = new_list;
	new_list->prev->next = new_list;
}

t_list	*lstnew(int data)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!list)
		exit_msg("lstlist : alloc error");
	list->data = data;
	list->next = list;
	list->prev = list;
	return (list);
}
