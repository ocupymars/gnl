#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < len)
		i++;
	while (src[j] && (i + j + 1) < len)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < len)
		dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}
