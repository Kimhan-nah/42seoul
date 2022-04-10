
#include "../includes/push_swap.h"

static void b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	int mid_a;
	int mid_b;
	int	size;

	mid_b = (min + max) / 2;
	mid_a = (min + mid_b) / 2;
	size = max - min + 1;
	if (size <= 3)
	{
		// small_sort();
		return ;
	}
	while (size > 0)
	{
		if (b->top->data > mid_b)
		{
			rotate(a, b, B);
		}
		else
		{
			push(b, a);
			if (a->top->data > mid_a)
			{
				rotate(a, b, A);
			}
		}
		size--;
	}

//	while (rb > 0)
//	{
//		reverse(a, b, B);				// rrb
//		rb--;
//	}
//
//	a_to_b(a, b, mid_a + 1, max);
//
//	b_to_a(a, b, min, mid_b);
//	b_to_a(a, b, mid_b + 1, mid_a);


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
		//small_sort();
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
//	t_operations *operations;
//
//	operations = (t_operations *)ft_calloc(1, sizeof(t_operations));
	a_to_b(a, b, 0, a->max);
}
