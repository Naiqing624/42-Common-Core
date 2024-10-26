#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    // Test %c
    printf("Testing %%c:\n");
    len1 = ft_printf("ft_printf: %c\n", 'A');
    len2 = printf("   printf: %c\n", 'A');
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %s
    printf("Testing %%s:\n");
    len1 = ft_printf("ft_printf: %s\n", "Hello, world!");
    len2 = printf("   printf: %s\n", "Hello, world!");
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %p (pointeurs)
    void *ptr = (void *)0x12345678;
    printf("Testing %%p:\n");
    len1 = ft_printf("ft_printf: %p\n", ptr);
    len2 = printf("   printf: %p\n", ptr);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %d et %i
    printf("Testing %%d and %%i:\n");
    len1 = ft_printf("ft_printf: %d, %i\n", 42, -42);
    len2 = printf("   printf: %d, %i\n", 42, -42);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %u (unsigned int)
    printf("Testing %%u:\n");
    len1 = ft_printf("ft_printf: %u\n", 3000000000U);
    len2 = printf("   printf: %u\n", 3000000000U);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %x et %X (hexadécimal)
    printf("Testing %%x and %%X:\n");
    len1 = ft_printf("ft_printf: %x, %X\n", 255, 255);
    len2 = printf("   printf: %x, %X\n", 255, 255);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test %%
    printf("Testing %%%%:\n");
    len1 = ft_printf("ft_printf: %%\n");
    len2 = printf("   printf: %%\n");
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test de valeurs spéciales (NULL pour les chaînes)
    printf("Testing NULL string:\n");
    len1 = ft_printf("ft_printf: %s\n", NULL);
    len2 = printf("   printf: %s\n", NULL == NULL ? "(null)" : NULL);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

     // Test des longueurs de chaînes
    len1 = ft_printf("ft_printf: '%s'\n", "test");
    len2 = printf("   printf: '%s'\n", "test");
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test des pointeurs NULL
    len1 = ft_printf("ft_printf: '%p'\n", (void *)0);
    len2 = printf("   printf: '%p'\n", (void *)0);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    // Test des valeurs numériques
    len1 = ft_printf("ft_printf: '%d'\n", 123);
    len2 = printf("   printf: '%d'\n", 123);
    printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

    return 0;
}
