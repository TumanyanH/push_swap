#include "../push_swap.h"

int find_high_ind(t_stacks stacks)
{
	int i;
	int temp;

	temp = 0;
	while (i < stacks.c.c_a)
	{
		if (stacks.stack_a[temp] < stacks.stack_a[i])
			temp = i;
		++i;
	}
	return (temp);
}

int max_five(t_stacks stacks)
{
	int index;
	int i = 0;
	int j = 0;

	while (i < stacks.c.c_a)
	{
		j = 0;
		index = find_high_ind(stacks);
		if (index == 1)
			swap('a', stacks.stack_a);
		else
			while (j < stacks.c.c_a - index)
			{
				r_rot('a', stacks.stack_a, stacks.c.c_a);
				++j;
			}
		if (check_stack(stacks))
			return (1);
	}
    return (0);
}