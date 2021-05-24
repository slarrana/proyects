#include "push_swap.h"

int	valid_char(const char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-' || n[i] == '+')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
		i++;
	if (n[i] != '\0')
		return (1);
	return (0);
}

int check_args(int argc, char **argv)
{
    int i;
    int n;

    i = 0;
    while (i < argc)
    {
	    if (valid_char(argv[i]))
		    return (-1);
        n = ft_atoi(argv[i]);
        if (n == 0 && ft_strncmp(argv[i], "0", 2) != 0)
            return (-1);
        i++;
    }
    return (0);
}

void    command(int argc, char **argv)
{
    char *comm;
    char *tmp;
    char *str;
    int i;

	i = 1;
    str = ft_strdup("");
    while (i > 0)
    {
	    i = get_next_line(0, &comm);
	    tmp = ft_strjoin(str, comm);
	    if (tmp[0] != '\0')
	    {
		    free(str);
		    str = ft_strjoin(tmp, "\n");
	    }
	    free(comm);
	    comm = NULL;
	    free(tmp);
    }
    if (str[0] != '\0')
	    if (str[ft_strlen(str) - 1] != '\0')
	    	str[ft_strlen(str) -1] = '\0';
    sort(argv, argc, str);
    free(str);
}

int main(int argc, char **argv)
{
	char **split;

    if (argc < 2)
    {
        printf("Error, numero de argumentos invalido\n");
        exit(-1);
    }
    if (check_args(argc - 1, &argv[1]) == -1)
    {
        printf("Error\n");
        exit(-1);
    }
    if (ft_string_space(argv[1]) == 0)
    {
   	command(argc - 1, &argv[1]);
    	return (check(&argv[1], argc - 1));
    }
    else if (ft_string_space(argv[1]) == 1 && argc == 2)
    {
	split = ft_split(argv[1], ' ');
	command(ft_words(argv[1], ' '), split);
	return (check(split, ft_words(argv[1], ' ')));
    }
    else
    {
	    printf("Error\n");
	    exit(-1);
    }
}
