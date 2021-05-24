#include "push_swap.h"

void com_s(char **list, int n)
{
    char *tmp;

    if (n > 1)
    {
        tmp = list[0];
        list[0] = list[1];
        list[1] = tmp;
    }
}

void    com_p(char **list_1, char **list_2, int n)
{
    char *tmp;
    int i;


    if (list_2[0])
    {
        tmp = list_1[0];
        list_1[0] = list_2[0];
        i = 1;
        while (i < n)
        {
            list_1[n - i] = list_1[n - i - 1];
            list_2[i - 1] = list_2[i];
            i++;
        }
        list_1[1] = tmp;
        list_2[n - 1] = NULL;
    }
}

void    com_r(char **list, int n)
{
    int i;
    char *tmp;

    i = 0;
    tmp = list[0];
    while (list[i + 1] && i < n)
    {
        list[i] = list[i + 1];
        i++;
    }
    list[i] = tmp;
}

void com_rr(char **list, int n)
{
    int i;
    int j;
    char *tmp;

    j = 0;
    while (j < n)
    {
        if (list[j])
            j++;
        else
            break;
    }
    i = 1;
    tmp = list[j - 1];
    while (j > 1 && list[j - 1])
    {
        list[j - i] = list[j - 2];
        j--;
    }
    list[0] = tmp;
}
