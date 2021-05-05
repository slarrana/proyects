#include "push_swap.h"

char *read_command()
{
    char *str;
    char *tmp;
    char buffer[5];
    int rd;

    str = ft_strdup("");
    while ((rd = read(1, buffer, 5)) > 1)
    {
        buffer[rd] = '\0';
        tmp = ft_strjoin(str, buffer);
        free(str);
        str = ft_strdup(tmp);
        free(tmp);
    }
    if (str[ft_strlen(str) - 1] == '\n')
        str[ft_strlen(str) -1] = '\0';
    return (str);
}

void exec_command(char **argv, char **list_b, int n, char *comando)
{
    if (ft_strncmp(comando, "sa", 3) == 0)
        com_s(argv, n);
    else if (ft_strncmp(comando, "sb", 3) == 0)
        com_s(list_b, n);
    else if (ft_strncmp(comando, "ss", 3) == 0)
    {
        com_s(argv, n);
        com_s(list_b, n);
    }
    else if (ft_strncmp(comando, "pa", 3) == 0)
        com_p(argv, list_b, n);
    else if (ft_strncmp(comando, "pb", 3) == 0)
        com_p(list_b, argv, n);
    else if (ft_strncmp(comando, "ra", 3) == 0)
        com_r(argv, n);
    else if (ft_strncmp(comando, "rb", 3) == 0)
        com_r(list_b, n);
    else if (ft_strncmp(comando, "rr", 3) == 0)
    {
        com_r(argv, n);
        com_r(list_b, n);
    }
    else if (ft_strncmp(comando, "rra", 4) == 0)
        com_rr(argv, n);
    else if (ft_strncmp(comando, "rrb", 4) == 0)
        com_rr(list_b, n);
    else if (ft_strncmp(comando, "rrr", 4) == 0)
    {
        com_rr(argv, n);
        com_rr(list_b, n);
    }
    else
    {
        printf("Error\n");
        exit(-1);
    }
}

void sort(char **argv, int n, char *comm)
{
    int i;
    int j;
    char *list_b[n];
    char comando[4];

    i = 0;
    while (i < n)
    {
        list_b[i] = NULL;
        i++;
    }
    i = 0;
    while (comm[i] != '\0')
    {
        j = 0;
        while (comm[i] != '\n' && comm[i] != '\0')
        {
            if (j > 3)
            {
                printf("Error, comando invalido\n");
                exit(-1);
            }
            comando[j] = comm[i];
            i++;
            j++;
        }
        comando[j] = '\0';
        exec_command(argv, list_b, n, comando);
        if (comm[i] == '\n')
            i++;
    }
}
