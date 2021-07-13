#include "libft.h"

int	ft_length(long n)
{
	if (n < 0)
		return (1 + ft_length(-n));
	else if (n < 10)
		return (1);
	else
		return (1 + ft_length(n / 10));
}
