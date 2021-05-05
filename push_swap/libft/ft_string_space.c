int     ft_string_space(char const *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] == ' ')
                        return (1);
                i++;
        }
        return (0);
}
