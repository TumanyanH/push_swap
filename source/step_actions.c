#include "../push_swap.h"

void swap(int *stack)
{
    int temp;

    temp = stack[1];
    stack[1] = stack[0];
    stack[0] = temp;
}

void push(char stack, t_stacks *stacks, int ac)
{
    if (stack == 'a')
    {
        shift_down(stacks->stack_a, ac);
        stacks->stack_a[0] = stacks->stack_b[0];
        shift_up(stacks->stack_b, ac);
    }
    else if (stack == 'b')
    {
        shift_down(stacks->stack_b, ac);
        stacks->stack_b[0] = stacks->stack_a[0];
        shift_up(stacks->stack_a, ac);
    }
}

void rotate(int *stack, int ac)
{
    int temp = stack[0];
    shift_up(stack, ac);
    stack[ac - 1] = temp;
}

void reverse_rotate(int *stack, int ac)
{

}