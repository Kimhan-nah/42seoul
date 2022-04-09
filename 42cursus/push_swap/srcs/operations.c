#include "../includes/push_swap.h"

// sa, sb
void	swap(t_stack *stack)
{
	t_list	*tmp;
	t_list *top;

	if (stack->len < 2)
		return ;
	tmp = stack->top;
	top = tmp->prev;

	stack->top = top;
	top->prev->next = tmp;

	tmp->prev = top->prev;
	tmp->next = top;

	top->prev = tmp;
	top->next = stack->head;
}

// pa, pb
void	push(t_stack *from, t_stack *to)
{
	t_list	*top;

	if (from->len < 1)
		return ;
	top = from->top;

	if (top == from->head)
		from->head = NULL;
	else
	{
		top->next->prev = top->prev;
		top->prev->next = top->next;
	}
	top->next = to->head;
	top->prev = to->top;
	lstadd_back(to, top);
	(from->len)--;
	(to->len)++;
}

// ra, rb, rr
void	rotate(t_stack *a, t_stack *b, int stack)
{
	if (stack == A)
	{
		a->head = a->top;
		a->top = a->head->prev;
	}
	else if (stack == B)
	{
		b->head = b->top;
		b->top = b->head->prev;
	}
	else
	{
		a->head = a->top;
		a->top = a->head->prev;
		b->head = b->top;
		b->top = b->head->prev;
	}
}

// rra, rrb, rrr
void	reverse(t_stack *a, t_stack *b, int stack)
{
	if (stack == A)
	{
		a->head = a->head->next;
		a->top = a->head->prev;
	}
	else if (stack == B)
	{
		b->head = b->head->next;
		b->top = b->head->prev;
	}
	else
	{
		a->head = a->head->next;
		a->top = a->head->prev;
		b->head = b->head->next;
		b->top = b->head->prev;
	}
}

// ss
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

