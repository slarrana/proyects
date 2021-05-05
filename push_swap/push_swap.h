#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

char *read_command();
void sort(char **argv, int n, char *comm);
void com_s(char **list, int n);
void com_p(char **list_1, char **list_2, int n);
void com_r(char **list, int n);
void com_rr(char **list, int n);
char **null_list(int n);
void exec_command(char **argv, char **list_b, int n, char *comando);
int check(char **argv, int n);
int check_swap(char **list_a, char **list_b, int n, char **str);
void push_swap(char **list_a, int n);
void check_value(int argc, char **argv);
void finish_push_swap(char **list_b, int n, char **str);
int control_loop(char **list_a, char **list_b, int n);
int check_push(char **list_a, char **list_b, int n, char **str);
int check_rotate(char **list_a, char **list_b, int n, char **str);
int do_push(char **list1, char **list2, int n, char **str);
void add_str(char **answer, char *str);

#endif

