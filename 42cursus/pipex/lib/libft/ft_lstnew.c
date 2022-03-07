/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:44:56 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/07 12:08:34 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!ret)
		exit(EXIT_FAILURE);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
