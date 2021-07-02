#include "../push_swap.h"

void fill(int **stack, int ac, char *args)
{
    int i = 0;
    int num = 0;
    int j = 0;
    int sign = 1;

    
    while (args[i] && (j <= ac))
    {
        if (args[i] == ' ')
        {

            // tb rewviewd
            if (args[0] == '-')
                sign *= -1;
            *stack[j++] = (num * sign);
            ++i;
        }
        num += ((args[i + 1] == ' ') ? 1 : 10) * (args[i] - '0');
        ++i;
    }
}

void fill_from_2d(int **stack, int ac, char **args)
{
    int i = 0;

    while (i <= ac)
    {
        *stack[i] = ft_itoa(args[i + 1]);
        ++i;
    }
    
}

void fill_stacks(t_stacks *stacks, int pt, int ac, char **argv)
{
    if (pt == 1)
    {
        fill(&stacks->stack_a, ac, argv[1]);
        fill(&stacks->stack_b, ac, argv[1]);
    }
    else if (pt == 2)
    {
        fill_from_2d(&stacks->stack_a, ac, argv);
        fill_from_2d(&stacks->stack_b, ac, argv);
    }
}