#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    if ((char)c == '\0')
    {
        return ((char *)s + i);
    }
    while (i >= 0)
    {
        if (s[i] == (char)c)
        {
            return ((char *)s + i);
        }
        i--;
    }
    return (NULL);
}

int	main()
{
	char	str[] = "sdfhskjhWdsf";
	char	c = 'W';
	printf("Result: %s\n", ft_strrchr(str, c));
	return 0;
}