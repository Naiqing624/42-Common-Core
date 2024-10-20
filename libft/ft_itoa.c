#include "libft.h"

static size_t get_len(int n)
{
    size_t  len;

    len = 0;
    if (n <= 0)
    {
        len++;
    }
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char    *str;
    size_t  len;
    long    nbr;

    nbr = n;
    len = get_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
    {
        return (NULL);
    }
    str[len] = '\0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    while (len > 0 && nbr != 0)
    {
        str[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (str);
}

int main(void)
{
    int i = -123469821;
    char    *a = ft_itoa(i);
    ft_putstr_fd(a, 1);
    return (0);
}