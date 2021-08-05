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

int in_chunck(int index, int chunck_num, int ch_s)
{
	return (index >= chunck_num * ch_s 
			&& index < chunck_num * ch_s + ch_s);
}

int find_nearest(t_stacks *stacks, int chunck_num)
{
	int i = 0;
	int temp1 = -1;
	int temp2 = 0;

	while (i < stacks->c.c_a)
	{
		if (in_chunck(stacks->stack_a[i].index, chunck_num, stacks->ch_s))
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
	int chunck_start = chunck_num * stacks->ch_s;
	int i = 0;
	int side = find_nearest(stacks, chunck_num);

	while (i < stacks->c.c_a)
	{
		if (stacks->c.c_b == stacks->ch_s)
			break;
		if (in_chunck(stacks->stack_a[0].index, chunck_num, stacks->ch_s))
			push('b', stacks, stacks->c.c_b);
		else
		{
			// if (side == 1)
				rot('a', stacks->stack_a, stacks->c.c_a);
			// else
				// r_rot('a', stacks->stack_a, stacks->c.c_a);
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

int max_hundred(t_stacks *stacks, int ch_s)
{
	int i = 0, x;
	int chuncks_count = stacks->c.c_a / ch_s;

	stacks->ch_s = ch_s;
	if (chuncks_count * stacks->ch_s != stacks->c.c_a)
		chuncks_count += 1;
	indexing(stacks);
	while (chuncks_count >= 0)
	{
		sort_chunck(stacks, chuncks_count);
		sort_b(stacks, chuncks_count);
		--chuncks_count;
	}
	// printf_stacks(stacks, (stacks->c.c_a + stacks->c.c_b));
    return (0);
}
