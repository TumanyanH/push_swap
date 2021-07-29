#include "../push_swap.h"

int find_min_nu_ind_new(t_stacks *stacks)
{
	int i = 0;
	int temp = 0;
	while (stacks->stack_a[temp].check != 0)
		++temp;		
	
	while (i < stacks->c.c_a)
	{
		// printf("check - %d\n", (stacks->stack_a[i].check));
		if (stacks->stack_a[i].check == 0)
		{
			if (stacks->stack_a[temp].num > stacks->stack_a[i].num
				&& stacks->stack_a[i].check != 1)
			{
				// printf("depq - %d\n", i);
				temp = i;
			}
		}
			++i;
	}
	printf("t - %d\n", temp);
	return (temp);
}

void indexing(t_stacks *stacks)
{
	int i = -1;
	int index = 0;

	while (++i < stacks->c.c_a)
		stacks->stack_a[i].check = 0;
	i = 0;
	while (i < stacks->c.c_a)
	{
		index = find_min_nu_ind_new(stacks);
		stacks->stack_a[index].index = i;
		stacks->stack_a[index].check = 1;
		++i;
	}
}

void sort_chunck()
{
	
}

int max_hundred(t_stacks *stacks)
{
	int i = 1;
	int chuncks_count = stacks->c.c_a / 20 + 1;

	indexing(stacks);
	while (i < chuncks_count + 1)
	{
		sort_chunck(i);
		++i;
	}
	
    return (0);
}
