
#include "../includes/push_swap.h"

static void b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	int size;

	size = max - min + 1;
	if (size <= 3)
	{
		// small_sort();
		return ;
	}


}

static void	a_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int pivot_a;
	int pivot_b;
	int	size;
	int rb;
	int pb;

	pivot_a = (min + max) / 2;
	pivot_b = pivot_a / 2;
	size = max - min + 1;
	rb = 0;
	pb = 0;
	if (size <= 3)
	{
		//small_sort();
		return ;
	}
	while (size > 0)
	{
		if (a->top->data > pivot_a)		// ra
			rotate(a, b, A);
		else							// pb
		{
			push(a, b);
			pb++;
//			(b->len)++;
			if (b->top->data > pivot_b)
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
	a_to_b(a, b, pivot_a + 1, max);
	b_to_a(a, b, min, pivot_a);
}

void	sort(t_stack *a, t_stack *b)
{
	a_to_b(a, b, 0, a->max);	
}
