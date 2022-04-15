#include "../includes/push_swap.h"

// sa, sb
void	swap(t_stack *stack, int ab)
{
	t_list	*tmp;

	if (ab == A)
		printf("sa\n");
	else if (ab == B)
		printf("sb\n");


	if (stack->len < 2)
		return ;

	tmp = stack->top->prev;					// tmp : bottom
	if (stack->len == 2)
	{
		stack->bottom = stack->top;
		stack->top = tmp;
	}
	else
	{
		tmp->prev->next = stack->top;			// top->next = stack->top			=>  bottom <-> top -> top 
		stack->top->prev = tmp->prev;
		
		stack->top->next = tmp;
		tmp->prev = stack->top;
		tmp->next = stack->bottom;

		stack->bottom->prev = tmp;
		stack->top = tmp;
	
	}


//	if (ab == A)
//		printf("A : ");
//	else if (ab == B)
//		printf("B : ");
//	lstprint(stack->top);
//	printf("\n");

}

// pa, pb
void	push(t_stack *from, t_stack *to, int ab)
{
	t_list	*top;

	if (from->len < 1)
		return ;
	if (ab == A)
		printf("pa\n");
	else
		printf("pb\n");

	top = from->top;

	if (from->top == from->bottom)
	{
		from->top = NULL;
		from->bottom = NULL;
	}
	else
	{
		top->next->prev = top->prev;
		top->prev->next = top->next;
		from->top = top->prev;
	}

	lstadd_back(to, top);

	(from->len)--;
	(to->len)++;

//	if (ab == A)
//		stackprint(to, from);
//	else if (ab == B)
//		stackprint(from, to);
}

// ra, rb, rr
void	rotate(t_stack *a, t_stack *b, int ab)
{
	if (ab == A)
	{
		printf("ra\n");
		a->bottom = a->top;
		a->top = a->bottom->prev;
	}
	else if (ab == B)
	{
		printf("rb\n");
		b->bottom = b->top;
		b->top = b->bottom->prev;
	}
	else
	{
		printf("rr\n");
		a->bottom = a->top;
		a->top = a->bottom->prev;
		b->bottom = b->top;
		b->top = b->bottom->prev;
	}

//	stackprint(a, b);
}

// rra, rrb, rrr
void	reverse(t_stack *a, t_stack *b, int ab)
{
	if (ab == A)
	{
		printf("rra\n");
		a->bottom = a->bottom->next;
		a->top = a->bottom->prev;
	}
	else if (ab == B)
	{
		printf("rrb\n");
		b->bottom = b->bottom->next;
		b->top = b->bottom->prev;
	}
	else
	{
		printf("rrr\n");
		a->bottom = a->bottom->next;
		a->top = a->bottom->prev;
		b->bottom = b->bottom->next;
		b->top = b->bottom->prev;
	}

//	stackprint(a, b);
}

//ss
void	ss(t_stack *a, t_stack *b)
{
	swap(a, AB);
	swap(b, AB);
	printf("ss\n");
}
