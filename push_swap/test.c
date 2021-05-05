#include "push_swap.h"

int check(char **argv, int n)
{
    int list[n];
    int i;

    i = 0;
    while (i < n)
    {
        if (!argv[i])
        {
            printf("KO\n");
            return (0);
        }
        list[i] = ft_atoi(argv[i]);
        i++;
    }
    i = 0;
    while (i < n - 1)
    {
        if (list[i] >= list[i + 1])
        {
            printf("KO\n");
            return (0);
        }
        i++;
    }
    printf("OK\n");
    return (1);
}
