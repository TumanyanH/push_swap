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

int in_chunck(int index, int chunck_num)
{
	return (index >= chunck_num * 20 
			&& index < chunck_num * 20 + 20);
}

int find_nearest(t_stacks *stacks, int chunck_num)
{
	int i = 0;
	int temp1 = -1;
	int temp2 = 0;

	while (i < stacks->c.c_a)
	{
		if (in_chunck(stacks->stack_a[i].index, chunck_num))
		{
			temp2 = i;
			if (temp1 == -1)
				temp1 = i;
		}
		++i;
	}
	if (temp1 > (stacks->c.c_a - temp2))
		return (-1);
	else 
		return (1);
}

void sort_chunck(t_stacks *stacks, int chunck_num)
{
	int chunck_start = chunck_num * 20;
	int i = 0;
	int side = find_nearest(stacks, chunck_num);

	while (i < stacks->c.c_a)
	{
		if (stacks->c.c_b == 20)
			break;
		if (in_chunck(stacks->stack_a[0].index, chunck_num))
			push('b', stacks, stacks->c.c_b);
		else
		{
			if (side == 1)
				rot('a', stacks->stack_a, stacks->c.c_a);
			else
				r_rot('a', stacks->stack_a, stacks->c.c_a);
			++i;
		}
	}
}

void	sort_b(t_stacks *stacks, int chunck_num)
{
	int i = 0, index;

	while (stacks->c.c_b)
	{
		index = find_high_ind('b', stacks);
		if (stacks->c.c_b / 2 >= index)
		{
			while (i < index)
			{
				rot('b', stacks->stack_b, stacks->c.c_b);
				++i;
			}
		}
		else
		{
			while (i < stacks->c.c_b - index)
			{
				r_rot('b', stacks->stack_b, stacks->c.c_b);
				++i;
			}
		}
		push('a', stacks, stacks->c.c_b);
		i = 0;
	}
}

int max_hundred(t_stacks *stacks)
{
	int i = 0, x;
	int chuncks_count = stacks->c.c_a / 20;

	if (chuncks_count * 20 != stacks->c.c_a)
		chuncks_count += 1;

	indexing(stacks);
	// printf_stacks(stacks, (stacks->c.c_a + stacks->c.c_b));
	// printf("1chunks -> %d\n", chuncks_count);
	while (i < chuncks_count)
	{
		sort_chunck(stacks, i);
		sort_b(stacks, i);
		// x = 0;
		// while (x < 20)
		// {
		// 	rot('a', stacks->stack_a, stacks->c.c_a);
		// 	++x;
		// }
		++i;
	}
	// printf_stacks(stacks, (stacks->c.c_a + stacks->c.c_b));
	
    return (0);
}
