#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		if (i >= start && a < len)
		{
			str[a] = s[i];
			a++;
		}
		i++;
	}
	str[a] = 0;
	return (str);
}
