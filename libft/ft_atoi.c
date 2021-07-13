#include "libft.h"

int	ft_atoi(const char *str)
{
	int	r;
	int	n;

	n = 1;
	r = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		++str;
	}
	return (r * n);
}
