#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stacks stacks;
    int args_count;
    int parse_type;
    args_count = 0;
    parse_type = check_args(&args_count, argc, argv);

    if (!(stacks.stack_a = malloc(args_count * sizeof(int)))
    || !(stacks.stack_b = malloc(args_count * sizeof(int))))
        ft_error("Something went wrong.");
    
    fill_stacks(&stacks, parse_type, args_count, argv);
	
	int i = 0;
	while (i < args_count)
	{
		printf("%d\n", stacks.stack_a[i]);
		i++;
	}
    return (0);
}