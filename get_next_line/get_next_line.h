# ifndef GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

#include    <stdlib.h>
#include    <unistd.h>

# ifndef    BUFFER_SIZE
# define    BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
void    ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);

#endif