/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:44:56 by hannkim           #+#    #+#             */
/*   Updated: 2022/02/24 14:51:52 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/so_long.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!ret)
		exit_with_message("Fail Alloc : lstnew");
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
