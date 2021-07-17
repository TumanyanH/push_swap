#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stacks stacks;
    int parse_type;

    stacks.c.c_a = 0;
    stacks.c.c_b = 0;
    parse_type = check_args(&stacks.c.c_a, argc, argv);

    if (!(stacks.stack_a = malloc((stacks.c.c_a + 1) * sizeof(int)))
    	|| !(stacks.stack_b = malloc((stacks.c.c_a + 1) * sizeof(int))))
        ft_error("Something went wrong.");

    fill_stacks(&stacks, parse_type, stacks.c.c_a, argv);
	// swap(stacks.stack_a);
    // push('b', &stacks, stacks.c.c_a);
    // rot(stacks.stack_a, stacks.c.c_a);
	// r_rot(stacks.stack_a, stacks.c.c_a);
	// printf_stacks(stacks, (stacks.c.c_a + stacks.c.c_b));
	sort(stacks);
    return (0);
}