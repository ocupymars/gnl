#include "libft.h"

int	ft_putnbr_base(unsigned long num, char *base)
{
	unsigned long	base_len;
	unsigned long	n;
	int				i;

	i = 1;
	n = num;
	base_len = ft_strlen(base);
	if (n == 0)
	{
		ft_putchar('0');
		return (i);
	}
	if (n >= base_len)
	{
		i += ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	else if (n < base_len)
		ft_putchar(base[n]);
	return (i);
}
