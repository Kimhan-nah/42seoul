
#include "../includes/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b, int min, int max);
static void b_to_a(t_stack *a, t_stack *b, int min, int max);

static void	small_sort_b(t_stack *a, t_stack *b, int size)
{
	printf("!!!!!!!!SMALL B!!!!!!!!\n");
	if (size == 2)
	{
		if (b->top->data < b->top->prev->data)
			swap(b, B);
	}
	else if (size == 3)
	{
		if (b->top->data < b->top->prev->data)
			swap(b, B);
		rotate(a, b, B);
		if (b->top->data < b->top->prev->data)
			swap(b, B);
		reverse(a, b, B);
		if (b->top->data < b->top->prev->data)
			swap(b, B);
	}
	while (size > 0)
	{
		push(b, a, A);		// pa
		size--;
	}
}

static void	small_sort_a(t_stack *a, t_stack *b, int size)
{
	printf("!!!!!!!!SMALL A!!!!!!!!\n");
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->top->data > a->top->prev->data)
			swap(a, A);
	}
	else if (size == 3)
	{
		if (a->top->data > a->top->prev->data)
			swap(a, A);
		rotate(a, b, A);
		if (a->top->data > a->top->prev->data)
			swap(a, A);
		reverse(a, b, A);
		if (a->top->data > a->top->prev->data)
			swap(a, A);
	}
}

static void b_to_a(t_stack *a, t_stack *b, int min, int max)
{
	printf("!!!!!!!!B->A (%d~ %d)!!!!!!!!\n", min, max);
	int mid_a;
	int mid_b;
	int	size;
	int	ra;
	int	rb;

	mid_b = (min + max) / 2;
	mid_a = (mid_b + max) / 2;
	size = max - min + 1;
	ra = 0;
	rb = 0;

	if (size <= 3)
	{
		small_sort_b(a, b, size);
		return ;
	}

	while (size > 0)
	{
		printf("===size %d===\n", size);
		if (b->top->data < mid_b)
		{
			rotate(a, b, B);
			rb++;
		}
		else
		{
			push(b, a, A);		// pa
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

	b_to_a(a, b, min, mid_b - 1);


	a_to_b(a, b, mid_a, max);				// 조금 더 큰 부분
	a_to_b(a, b, mid_b, mid_a - 1);		// 조금 더 작은 부분

}

static void	a_to_b(t_stack *a, t_stack *b, int min, int max)
{
	printf("!!!!!!!!A->B (%d~%d)!!!!!!!!\n", min, max);
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
		small_sort_a(a, b, size);
//		b_to_a(a, b, min, mid_b);
//		b_to_a(a, b, mid_b + 1, mid_a);
		return ;
	}
	while (size > 0)
	{
		printf("===size %d===\n", size);
		if (a->top->data > mid_a)		// ra
		{
			rotate(a, b, A);
			ra++;
		}			
		else							// pb
		{
			push(a, b, B);
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

	b_to_a(a, b, mid_b + 1, mid_a);		// 조금 더 큰 부분
	b_to_a(a, b, min, mid_b);			// 조금 더 작은 부분
}

void	sort(t_stack *a, t_stack *b)
{
	a_to_b(a, b, 0, a->max);
//	if (a->top->data > a->top->prev->data)
//		swap(a, A);
}
