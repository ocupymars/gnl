#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
	char c = '0';
	
	ft_printf("%*c\n", 10, c);
	printf("%*c\n", 10, c);

}