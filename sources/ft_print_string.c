#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_str_length(char *s, t_printf *data, int len)
{
	if (s)
		len = ft_strlen(s);
	if (data->precision > 0 && len > data->precision)
		len = data->precision;
	return (len);
}

void	ft_print_string(t_printf *data)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	s = va_arg(data->args, char *);
	if (!s)
		s = NULL;
	if (s && data->point == 1 && data->precision == 0)
		data->print += write(1, " ", 1);
	len = ft_str_length(s, data, len);
	if (!data->dash && data->width > len)
		ft_default_justifycs(data, len);
	if (data->precision > 0)
		while (s[i] && data->precision--)
			data->print += write(1, &s[i++], 1);
	else
		while (s[i])
			data->print += write(1, &s[i++], 1);
	if (s && data->dash && data->width)
		ft_left_justifycs(data, len);
}
