/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/03 15:24:53 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1
# define AB 2

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct s_list	*head;
	int				len;
}	t_stack;

void	exit_msg(char *str);
void	parsing(char **argv, t_stack *a);
t_list	*lstnew(int data);
void	lstadd_back(t_stack *stack, t_list *new_list);
void	lstprint(t_list *head);

#endif

