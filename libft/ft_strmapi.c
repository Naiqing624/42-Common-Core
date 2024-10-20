#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    size_t  len;
    int i;

    if (!s || !f)
    {
        return (NULL);
    }
    len = ft_strlen(s);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
    {
        return (NULL);
    }
    i = 0;
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

#include <ctype.h>

char toggle_case_by_index(unsigned int index, char c)
{
    if (index % 2 == 0)
        return (char)toupper(c); 
    else
        return (char)tolower(c); 
}

int main()
{
    char original[] = "HELLO, WORLD!";
    char *result = ft_strmapi(original, toggle_case_by_index);
    
    if (result)
    {
        printf("Original: %s\n", original);
        printf("Modified: %s\n", result);
        free(result);
    }
    else
    {
        printf("Error allocating memory!\n");
    }
    
    return 0;
}

