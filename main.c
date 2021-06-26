#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stacks stacks;
    int args_count;

    args_count = 0;
    check_args(&args_count, argc, argv);
    if (!(stacks.stack_a = malloc(args_count * sizeof(int)))
    || !(stacks.stack_b = malloc(args_count * sizeof(int))))
        ft_error("Something went wrong.");
    return (0);
}