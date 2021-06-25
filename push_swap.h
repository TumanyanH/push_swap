#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
    int num;
    struct s_stack *next;
} t_stack;

int check_all_num(t_stack stack, char *arg);
int check_all_num_2d(t_stack stack, char **arg);
int check_args(char argc, char **args);
int error(char *text);
void ft_putstr(char *str);
t_stack *addToList(t_stack last, int new_num);


#endif
