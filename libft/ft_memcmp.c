#include "libft.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptr1;
    const unsigned char *ptr2;

    ptr1 = (const unsigned char *)s1;
    ptr2 = (const unsigned char *)s2;
    while (n > 0)
    {
        if (*ptr1 != *ptr2)
        {
            return (*ptr1 - *ptr2);
        }
        ptr1++;
        ptr2++;
        n--;
    }
    return (0);
}

int main(void)
{
    char    str[] = "sqdjh";
    char    str1[] = "dshkhk";
    int result = (ft_memcmp(str, str1, 3) > 0);
    if (result == 0)
    {
        printf("same");
    }
    else
    {
        printf("not same");
    }
}