#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stacks stacks;
    int args_count;
    int parse_type;
    args_count = 0;
    parse_type = check_args(&args_count, argc, argv);

    if (!(stacks.stack_a = malloc((args_count + 1) * sizeof(int)))
    || !(stacks.stack_b = malloc((args_count + 1) * sizeof(int))))
        ft_error("Something went wrong.");

    fill_stacks(&stacks, parse_type, args_count, argv);
	swap(stacks.stack_a);
    push('b', &stacks, args_count);
    rotate(stacks.stack_a, args_count);
	printf_stacks(stacks, args_count);
    return (0);
}