#include "libft.h"

char	*ft_itoa_base(char *str, unsigned int num, int base, int c)
{
	int		i;

	i = 0;
	if (num == 0)
		str[i] = '0';
	while (num > 0)
	{
		if (base > 10 && (num % base >= 10))
			str[i++] = (num % base) - 10 + c;
		else
			str[i++] = (num % base) + '0';
		num /= base;
	}
	str[i] = '\0';
	return (str);
}
