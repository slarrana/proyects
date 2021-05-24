#include "push_swap.h"

void add_str(char **answer, char *str)
{
    char *join;

    join = ft_strjoin(*answer, str);
    free(*answer);
    *answer = ft_strdup(join);
    free(join);
}

int    check_swap(char **list_a, char **list_b, int n, char **str)
{
    int a1;
    int a2;
    int b1;
    int b2;

    if (n < 2)
        return (0);
    if (list_a[0])
        a1 = ft_atoi(list_a[0]);
    if (list_a[1])
        a2 = ft_atoi(list_a[1]);
    if (list_b[0])
        b1 = ft_atoi(list_b[0]);
    if (list_b[1])
        b2 = ft_atoi(list_b[1]);
    if (list_a[0] && list_a[1] && list_b[0] && list_b[1])
    {
        if (a2 < a1 && b2 > b1)
        {
            com_s(list_a, n);
            com_s(list_b, n);
            add_str(str, "ss\n");
            return (1);
        }
    }
    if (list_a[0] && list_a[1])
    {
        if (a2 < a1)
        {
            com_s(list_a, n);
            add_str(str, "sa\n");
            return (1);
        }
    }
    if (list_b[0] && list_b[1])
    {
        if (b2 > b1)
        {
            com_s(list_b, n);
            add_str(str, "sb\n");
            return (1);
        }
    }
    return (0);
}

int check_rotate(char **list_a, char **list_b, int n, char **str)
{
    int i;
    int j;

    if (n < 2)
        return (0);
    i = 0;
    while (list_a[i] && i < n)
	    i++;
    j = 0;
    while (list_b[j] && j < n)
	    j++;
    if (list_a[0] && list_b[0] && i > 1 && j > 1)
    {
        if ((ft_atoi(list_a[0]) > ft_atoi(list_a[i - 1]) && ft_atoi(list_b[0]) < ft_atoi(list_b[j - 1]))
	|| (ft_atoi(list_a[1]) > ft_atoi(list_a[i - 1]) && ft_atoi(list_b[1]) < ft_atoi(list_b[j - 1])))
        {
            com_r(list_a, n);
            com_r(list_b, n);
            add_str(str, "rr\n");
	    return (1);
        }
    }
    if (list_a[0] && i > 1)
    {
        if (ft_atoi(list_a[0]) > ft_atoi(list_a[i - 1]) && ft_atoi(list_a[1]) > ft_atoi(list_a[i - 1]))
        {
            com_rr(list_a, n);
            add_str(str, "rra\n");
	    return (1);
        }
	else if (ft_atoi(list_a[0]) > ft_atoi(list_a[i - 1]))
        {
            com_r(list_a, n);
            add_str(str, "ra\n");
	    return (1);
        }
    }
    if(list_b[0] && j > 1)
    {
        if (ft_atoi(list_b[0]) < ft_atoi(list_b[j - 1]) && ft_atoi(list_b[1]) < ft_atoi(list_b[j - 1]))
        {
            com_rr(list_b, n);
            add_str(str, "rrb\n");
			return (1);
        }
	else if (ft_atoi(list_b[0]) < ft_atoi(list_b[j - 1]))
        {
            com_r(list_b, n);
            add_str(str, "rb\n");
			return (1);
        }
    }
    return (0);
}

int	check_pb(char **list1, char **list2, int n, char **str)
{
	int i;

	i = 0;
	while (list1[i] && list1[i + 1] && i < n - 1)
	{
		if (ft_atoi(list1[i]) > ft_atoi(list1[i + 1]))
			return (0);
		i++;
	}
	if (list2[0] && list1[0])
	{
		if (ft_atoi(list2[0]) < ft_atoi(list1[0]))
		{
			com_p(list1, list2, n);
			add_str(str, "pa\n");
			return (1);
		}
	}
	if (list2[0] && !list1[0])
	{
		com_p(list1, list2, n);
		add_str(str, "pa\n");
		return (1);
	}
	return (0);
}

int	comprobar_lista(char **list, int n)
{
	int i;

	i = 0;
	while (list[i] && list[i + 1] && i < n - 1)
	{
		if (ft_atoi(list[i]) > ft_atoi(list[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int do_push(char **list1, char **list2, int n, char **str)
{
    int i;
    int num;

    if (list1[0])
        num = ft_atoi(list1[0]);
    else
        return (check_pb(list1, list2, n, str));
    i = 1;
    while (i < n && list1[i])
    {
        if (num > ft_atoi(list1[i]))
        {
            com_p(list2, list1, n);
            add_str(str, "pb\n");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        num = 0;
        while (num < n)
        {
            if (!list1[i] || !list2[num])
                break ;
            if (ft_atoi(list1[i]) > ft_atoi(list2[num]) && comprobar_lista(list1, n))
            {
                com_p(list2, list1, n);
                add_str(str, "pb\n");
                return (1);
            }
            num++;
        }
        i++;
    }
    if (list1[0] && list2[0])
    {
	    if (ft_atoi(list1[0]) < ft_atoi(list2[0]))
	    {
		    com_p(list2, list1, n);
		    add_str(str, "pb\n");
		    return (1);
	    }
    }
    if (comprobar_lista(list1, n))
    {
	    com_p(list2, list1, n);
	    add_str(str, "pb\n");
	    return (1);
    }
    else if (list2[0])
    {
	    if (ft_atoi(list2[0]) < ft_atoi(list1[0]))
	    {
		    com_p(list1, list2, n);
		    add_str(str, "pa\n");
		    return (1);
	    }
    }
	
    return (0);
}

int check_push(char **list_a, char **list_b, int n, char **str)
{
    return(do_push(list_a, list_b, n, str));
}

int control_loop(char **list_a, char **list_b, int n)
{
    int i;

    i = 0;
    if (list_a[i] && list_b[i])
    {
        if (ft_atoi(list_a[0]) < ft_atoi(list_b[0]))
            return (0);
    }
    while (i < n - 1)
    {
        if (list_a[i] && list_a[i + 1])
        {
            if (ft_atoi(list_a[i]) > ft_atoi(list_a[i + 1]))
                return(0);
        }
        if (list_b[i] && list_b[i + 1])
        {
            if (ft_atoi(list_b[i]) < ft_atoi(list_b[i + 1]))
                return (0);
        }
        i++;
    }
    return (1);
}

void finish_push_swap(char **list_b, int n, char **str)
{
	int i;
	
	i = 0;
	while (i < n && list_b[i])
	{
	    add_str(str, "pa\n");
	    i++;
	}
	ft_putstr_fd(*str, 1);
	free(*str);
	*str = NULL;
	exit (1);
}

void push_swap(char **list_a, int n)
{
    int i;
    int flag;
    char *str;
    char *list_b[n];

    i = 0;
    while(i < n)
    {
        list_b[i] = NULL;
        i++;
    }
    i = 0;
    str = ft_strdup("");
    while (i == 0)
    {
        flag = check_rotate(list_a, list_b, n, &str);
	if (flag == 0)
		flag = check_swap(list_a, list_b, n, &str);
	if (flag == 0)
		flag = check_push(list_a, list_b, n, &str);
        i = control_loop(list_a, list_b, n);
    }
    finish_push_swap(list_b, n, &str);
}

void    check_value(int argc, char **argv)
{
    int i;
    int j;
    int list[argc];

    i = 0;
    while (i < argc)
    {
        list[i] = ft_atoi(argv[i]);
        if (list[i] == 0 && ft_strncmp(argv[i], "0", 2) != 0)
        {
            printf("Error\n");
            exit(-1);
        }
        i++;
    }
    i = 0;
    while (i < argc)
    {
		j = 0;
		while (j < argc / 2)
		{
			if (i != j && list[i] == list[j])
			{
				printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
    }
}

int main(int argc, char **argv)
{
	char **split;

    if (argc < 2)
        return (0);
    if (ft_string_space(argv[1]) == 0)
    {
	    check_value(argc - 1, &argv[1]);
	    push_swap(&argv[1], argc - 1);
	   
	    exit(0);
    }
    else if (ft_string_space(argv[1]) == 1 && argc == 2)
    {
	split = ft_split(argv[1], ' ');
	check_value(ft_words(argv[1], ' '), split);
	push_swap(split, ft_words(argv[1], ' '));
	exit(0);
    }
    else
    {
	    printf("Error\n");
	    exit(0);
    }
}
