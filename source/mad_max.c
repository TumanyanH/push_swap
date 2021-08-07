#include "../push_swap.h"

void stack_to_b_top(t_stacks *stacks, int mid_ind, int check);
void stack_to_b_bottom(t_stacks *stacks, int mid_ind, int check);

void stack_to_b_top(t_stacks *stacks, int mid_ind, int check)
{
	int i = 0;
	
	while (stacks->c.c_b < mid_ind)
	{
		if (!check)
		{
			if (stacks->stack_a[i].index >= mid_ind)
				stack_to_b_bottom(stacks, mid_ind, 0);
			push('b', stacks, stacks->c.c_a);
			++i;
		}
		else
		{
			if (stacks->stack_a[i].index > mid_ind)
				rot('a', stacks->stack_a, stacks->c.c_a);
			else
				push('b', stacks, stacks->c.c_a);
			++i;
		}
	}
}

void stack_to_b_bottom(t_stacks *stacks, int mid_ind, int check)
{
	int i = stacks->c.c_a - 1;

	while (stacks->c.c_b < mid_ind)
	{
		if (stacks->stack_a[i].index >= mid_ind)
			stack_to_b_top(stacks, mid_ind, 1);
		r_rot('a', stacks->stack_a, stacks->c.c_a);
		push('b', stacks, stacks->c.c_a);

		--i;
	}
}

int mad_max(t_stacks *stacks)
{
	int mid_ind, i;

	indexing(stacks);
	mid_ind = stacks->stack_a[find_high_ind('a', stacks)].index / 2;
	if (stacks->c.c_a % 2 == 0)
		++mid_ind;
	i = mid_ind;
	printf("med - %d\n", mid_ind);
	// while (stacks->c.c_a / 2 > 1)
	// {
		stack_to_b_top(stacks, mid_ind, 0);
		mid_ind = stacks->c.c_a / 2 + 1;
		printf_stacks(stacks, (stacks->c.c_a + stacks->c.c_b));
	// }
	
	return (0);
}