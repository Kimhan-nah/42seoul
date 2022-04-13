
#include "../includes/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b, int min, int max);
static void b_to_a(t_stack *a, t_stack *b, int min, int max);

static void	small_sort(t_stack *a, t_stack *b, int min, int max)
{
	int size;

	size = max - min + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->top->data == max)
			swap(a);
	}
	else if (size == 3)
	{
		if (a->top->data > a->top->prev->data)
			swap(a);
		rotate(a, b, A);
		if (a->top->data > a->top->prev->data)
			swap(a);
		reverse(a, b, A);
		if (a->top->data > a->top->prev->data)
			swap(a);
	}
}

static void b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	int mid_a;
	int mid_b;
	int	size;
	int	ra;
	int	rb;

	mid_b = (min + max) / 2;
	mid_a = (min + mid_b) / 2;
	size = max - min + 1;
	ra = 0;
	rb = 0;
	if (size <= 3)
	{
		// small_sort(); => 필요 없지 않나?	 a_to_b에서만 하면 될듯?
		return ;
	}
	while (size > 0)
	{
		if (b->top->data < mid_b)
		{
			rotate(a, b, B);
			rb++;
		}
		else
		{
			push(b, a);
			if (a->top->data < mid_a)
			{
				rotate(a, b, A);
				ra++;
			}
		}
		size--;
	}


	// rrr 추가하기
	while (ra > 0)
	{
		reverse(a, b, A);				// rra
		ra--;
	}

	while (rb > 0)
	{
		reverse(a, b, B);				// rrb
		rb--;
	}

	b_to_a(a, b, min, mid_b);

	a_to_b(a, b, mid_a, max);
	a_to_b(a, b, mid_b + 1, mid_a - 1);
}

static void	a_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int mid_a;
	int mid_b;
	int	size;
	int	ra;
	int rb;
	int pb;

	mid_a = (min + max) / 2;			// pivot_a
	mid_b = (min + mid_a) / 2;				// pivot_b
	size = max - min + 1;
	ra = 0;
	rb = 0;
	pb = 0;
	if (size <= 3)
	{
		small_sort(a, b, min, max);
		return ;
	}
	while (size > 0)
	{
		if (a->top->data > mid_a)		// ra
		{
			rotate(a, b, A);
			ra++;
		}			
		else							// pb
		{
			push(a, b);
			pb++;
			if (b->top->data > mid_b)
			{
				rotate(a, b, B);		// rb
				rb++;
			}
		}
		size--;
	}


	// rrr 추가하기
	while (ra > 0)
	{
		reverse(a, b, A);				// rra
		ra--;
	}

	while (rb > 0)
	{
		reverse(a, b, B);				// rrb
		rb--;
	}

	a_to_b(a, b, mid_a + 1, max);

	b_to_a(a, b, min, mid_b);
	b_to_a(a, b, mid_b + 1, mid_a);
}

void	sort(t_stack *a, t_stack *b)
{
	a_to_b(a, b, 0, a->max);
}
