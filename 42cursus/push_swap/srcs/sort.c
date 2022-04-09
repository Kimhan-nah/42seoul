
#include "../includes/push_swap.h"

static void	rrr(t_operations *operations, t_stack *a, t_stack *b)
{
	int ra;
	int rb;
	int rrr;

	ra = operations->ra;
	rb = operations->rb;
	rrr = 0;
	if (ra > 0 && rb > 0)
	{
		if (ra < rb)
			rrr = ra;
		else
			rrr = rb;
		ra -= rrr;
		rb -= rrr;
	}
	while (rrr > 0)
		reverse(a, b, AB);
	while (ra > 0)
		reverse(a, b, A);
	while (rb > 0)
		reverse(a, b, B);
}

static void b_to_a(t_operations *operations, t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
}

static void	a_to_b(t_operations *operations, t_stack *a, t_stack *b)
{
	int	count;
	int pivot_b;		// small pivot

	count = a->len;
	while (count > 0)
	{
		a->min = (a->min + a->max) / 2;		// a->min : big pivot
		pivot_b = a->min / 2;
		if (a->top->data >= a->min)		// 큰 값 아래로 보내기 : ra
		{
			rotate(a, b, A);
			operations->ra++;
		}
		else							// 작은 값 b로 보내기 : pb
		{
			push(a, b);
			operations->pb++;
			(a->len)--;
			(b->len)++;
			if (b->top->data > pivot_b)		// 큰 값 아래로 보내기 : rb
			{
				rotate(a, b, B);
				operations->rb++;
			}
		}
		count--;
	}
	// rrr이 아니라 rrb 만 하면 되는 거 아님??? 왜 rrr 하고 ra 남은 횟수가 나온다는 거?
	
	rrr(operations, a, b);

	// small_sort()

}

void	sort(t_stack *a, t_stack *b)
{
	t_operations	*operations;

	operations = (t_operations *)ft_calloc(1, sizeof(t_operations));
	a_to_b(operations, a, b);	
	b_to_a(operations, a, b);
}
