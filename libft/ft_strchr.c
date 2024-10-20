#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}

int main(void)
{
    const char str[] = "hello";
    printf("%s", ft_strchr(str, 'l'));
    return (0);
}