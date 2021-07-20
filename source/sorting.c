#include "../push_swap.h"

int		find_min_nu_ind(char s_t, t_stacks *stacks)
{
	int count = (s_t == 'a') ? stacks->c.c_a : stacks->c.c_b;
	int *stack = (s_t == 'a') ? stacks->stack_a : stacks->stack_b;
	int i = 0;
	int temp = 0;

	while (i < count)
	{
		if (stack[temp] > stack[i])
			temp = i;
		++i;
	}
	return (temp);
}

int back_fill(t_stacks *stacks)
{
	while (stacks->c.c_b > 0)
		push('a', stacks, stacks->c.c_b);
	return (0);
}

int to_b(t_stacks *stacks)
{
	return 0;
}

void	sort(t_stacks stacks)
{
	if (!check_stack(stacks))
	{
		if (stacks.c.c_a <= 5)
			max_five(stacks);
		// else if (stacks.c.c_a < 100)
			// max_hundred();
		// else 
			// mad_max();
	}
}
