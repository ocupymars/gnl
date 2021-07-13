#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_string(t_printf *data)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	str = va_arg(data->args, char *);
	if (!str)
		str = "(null)";
	if (str && data->point == 1 && data->precision == 0)
		return (ft_zero_precision(data));
	len = ft_str_length(str, data, len);
	if (!data->dash && data->width > len)
		ft_default_justify_cs(data, len);
	if (data->precision > 0)
		while (str[i] && data->precision--)
			data->print += write(1, &str[i++], 1);
	else
		while (str[i])
			data->print += write(1, &str[i++], 1);
	if (str && data->dash && data->width)
		ft_left_justify_cs(data, len);
}
