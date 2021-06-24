#include "../push_swap.h"

int is_digit_string(char *num)
{
    while (*num)
    {
        if (!ft_isdigit(*num) || *num == ' ')
            return (0);
        ++num;
    }
    return (1);
}

int to_space_atoi(char *string)
{
    int num = 0;

    while (*string && *string != ' ')
    {
        num += 10 * (*string - '0');
        (*string)++;
    }
    return (num);
}

int check_all_num(t_stack stack, char *arg)
{
    int i;
    int num = 0;

    i = 0;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]) || arg[i] != ' ')
            error("1Error, non-digits detected");
        while (arg[i] && ft_isdigit(arg[i]))
        {
            num += ((arg[i + 1] == ' ') ? 1 : 10) * (arg[i] - '0');
            ++i;
        }
        stack.next = addToList(stack, num);
        i++;
    }
    return (1);
}

int check_all_num_2d(t_stack stack, char **arg)
{
    int i;

    i = 1;
    while (arg[i])
    {
        if (!is_digit_string(arg[i]))
            error("Error, non-digits detected");
        stack.next = addToList(stack, ft_atoi(arg[i]));
        i++;
    }
    return (1);
}

int check_args(char argc, char **args)
{
    t_stack stack_a;

    if (argc == 2)
        check_all_num(stack_a, args[1]);
    else if (argc >= 2)
        check_all_num_2d(stack_a, args);
    else if (argc)
        error("No any digits.");
    return (0);
}