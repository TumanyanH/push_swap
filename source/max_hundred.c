#include "../push_swap.h"

int find_min_nu_ind_new(t_stacks *stacks)
{
	int i = 0;
	int temp = 0;
	while (stacks->stack_a[temp].check != 0)
		++temp;		
	
	while (i < stacks->c.c_a)
	{
		if (stacks->stack_a[i].check == 0)
		{
			if (stacks->stack_a[temp].num > stacks->stack_a[i].num
				&& stacks->stack_a[i].check != 1)
				temp = i;
		}
			++i;
	}
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

void sort_chunck(t_stacks *stacks, int chunck_num)
{
	int i = chunck_num * 20;

	while (i < (chunck_num * 20 + 20))
	{
		
		++i;
	}
}

int max_hundred(t_stacks *stacks)
{
	int i = 1;
	int chuncks_count = stacks->c.c_a / 20;

	if (chuncks_count * 20 != stacks->c.c_a)
		chuncks_count += 1;

	indexing(stacks);

	printf("chunks -> %d\n", chuncks_count);
	while (i <= chuncks_count)
	{
		sort_chunck(stacks, i);
		++i;
	}
	
    return (0);
}
