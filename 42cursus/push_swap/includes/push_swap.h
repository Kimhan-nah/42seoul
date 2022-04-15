/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/14 20:28:54 by hannah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define A 0
# define B 1
# define AB 2

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct s_list	*top;
	struct s_list	*bottom;
	int				len;
	int				max;
	int				min;
}	t_stack;

typedef struct	s_operations
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	sa;
	int	sb;
	int	ss;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operations;

void	exit_msg();
void	parsing(char **argv, t_stack *a);
t_list	*lstnew(int data);
void	lstadd_back(t_stack *stack, t_list *new_list);
void	lstadd_front(t_stack *stack, t_list *new_list);
void	lstprint(t_list *head);
void	sort(t_stack *a, t_stack *b);

void	swap(t_stack *stack, int ab);
void	push(t_stack *from, t_stack *to, int ab);
void	rotate(t_stack *a, t_stack *b, int ab);
void	reverse(t_stack *a, t_stack *b, int ab);
void	ss(t_stack *a, t_stack *b);


void	stackprint(t_stack *a, t_stack *b);

#endif

