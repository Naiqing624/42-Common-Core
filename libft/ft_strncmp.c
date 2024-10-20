#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0 && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
    {
        return (0);
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int main(void)
{
    const char str1[] = "Hello";
    const char str2[] = "Holle";
    int result = ft_strncmp(str1, str2, 5);
    printf("%d", result);
}