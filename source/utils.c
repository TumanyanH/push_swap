#include "../push_swap.h"

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        ++str;
    }
}

void printf_stacks(t_stacks stacks, int args_count)
{
    int i = 0;

    while (i < args_count)
    {
        printf("%d  %d\n", stacks.stack_a[i], stacks.stack_b[i]);
        ++i;
    }
    printf("-  -\n");
    printf("a  b\n");
}

void shift_up(int *stack, int args_count)
{
    int i = 0;

    while (i < args_count)
    {
        stack[i] = stack[i + 1];
        ++i;
    }
}

void shift_down(int *stack, int args_count)
{
    int i = 1;

    while (i < args_count)
    {
        stack[i] = stack[i - 1];
        ++i;
    }
}