#include "../inc/push_swap.h"

int	is_syntax(char *str)
{
	if (!str || !*str)
		return (1);
	if (!(*str == '+' || *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*str)
	{
        if ((*str == '+' || *str == '-'))
		    str++;
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int main(void)
{
	char input[100];

	printf("Enter a string to test syntax: ");
	scanf("%s", input);

	if (is_syntax(input) == 0)
		printf("Valid syntax.\n");
	else
		printf("Invalid syntax.\n");

	return 0;
}