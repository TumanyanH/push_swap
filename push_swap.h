#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define CHECK_ALLOWED_CHARS(c) (c != ' ' && !ft_isdigit(c) && c != '-')

typedef struct s_stack
{
    int num;
    struct s_stack *next;
} t_stack;

typedef struct s_stacks {
    int *stack_a;
    int *stack_b;
} t_stacks;

int 		check_all_num(int *args_count, char *arg);
int 		check_all_num_2d(int *args_count, char **arg);
int 		check_args(int *args_count, char argc, char **args);
int 		ft_error(char *text);
void 		ft_putstr(char *str);
t_stack 	*addToList(t_stack last, int new_num);
void 		fill_stacks(t_stacks *stacks, int pt, int ac, char **argv);


void printf_stacks(t_stacks stacks, int args_count);
void shift_up(int *stack, int args_count);
void shift_down(int *stack, int args_count);

// actions 
void swap(int *stack);
void push(char stack, t_stacks *stacks, int ac);
void rotate(int *stack, int ac);


#endif
