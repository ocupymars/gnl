#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	char	*dest;
	int		len;

	len = ft_length(n);
	dest = (char *)malloc((len + 1) * (sizeof (char)));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (n == 0)
		dest[len] = 0 + '0';
	while (n > 0)
	{
		dest[len--] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
