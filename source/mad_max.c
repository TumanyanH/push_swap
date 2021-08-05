#include "../push_swap.h"

void stack_to_b_top(t_stacks *stacks, int mid_ind, int rot);
void stack_to_b_bottom(t_stacks *stacks, int mid_ind, int rot);

void stack_to_b_top(t_stacks *stacks, int mid_ind, int rot)
{
	int i = 0;

	
	while (i <= mid_ind)
	{
		if (stacks->stack_a[i].index <= mid_ind)
			stack_to_b_bottom(stacks, mid_ind, 0);
		push('b', stacks, stacks->c.c_a);
		++i;
	}
}

void stack_to_b_bottom(t_stacks *stacks, int mid_ind, int rot)
{
	int i = mid_ind;

	while (i >= 0)
	{
		if (stacks->stack_a[i].index <= mid_ind)
			stack_to_b_top(stacks, mid_ind, 0);
		r_rot('a', stacks->stack_a, stacks->c.c_a);
		push('b', stacks, stacks->c.c_a);
		--i;
	}
}

int mad_max(t_stacks *stacks)
{
	int mid_ind;

	mid_ind = stacks->c.c_a / 2;
	while (stacks->c.c_a / 2 > 1)
	{
		stack_to_b_top(stacks, mid_ind);
		mid_ind = stacks->c.c_a / 2 + 1;
	}
	return (0);
}