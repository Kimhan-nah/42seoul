/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:06:50 by hannkim           #+#    #+#             */
/*   Updated: 2022/04/15 17:37:53 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdlib.h>

# define A 0
# define B 1
# define AB 2

typedef struct s_list
{
	int				data;
	int				idx;
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

void	exit_msg(void);
void	parsing(char **argv, t_stack *a);
void	precheck(t_stack *a);
void	value_swap(int *arr, int i, int j);

t_list	*lstnew(int data);
void	lstadd_back(t_stack *stack, t_list *new_list);
void	lstadd_front(t_stack *stack, t_list *new_list);

void	sort(t_stack *a, t_stack *b);
void	a_to_b(t_stack *a, t_stack *b, int min, int max);
void	b_to_a(t_stack *a, t_stack *b, int min, int max);
void	rollback(t_stack *a, t_stack *b, int *cnt, int ab);

void	swap(t_stack *stack, int ab);
void	push(t_stack *from, t_stack *to, int ab);
void	rotate(t_stack *a, t_stack *b, int ab, int *cnt);
void	reverse(t_stack *a, t_stack *b, int ab);
void	ss(t_stack *a, t_stack *b);

void	three_sort(t_stack *a, t_stack *b, int min, int max);
void	five_sort(t_stack *a, t_stack *b, int size);
void	small_sort_b(t_stack *a, t_stack *b, int size);
void	small_sort_a(t_stack *a, t_stack *b, int size);

#endif
