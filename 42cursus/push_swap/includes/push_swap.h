/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/16 13:15:19 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				*data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_lst
{
	t_node	head;
	int		size;
}	t_lst;

typedef struct s_stack
{
	int				*content;
	struct s_stack	*next;
}	t_stack;

#endif

