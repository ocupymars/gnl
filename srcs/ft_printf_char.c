#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_printf *data)
{
	char	c;

	c = va_arg(data->args, int);
	ft_set_printf_data(data, 1);
	if (data->width && !data->minus)
	{
		ft_default_justify_cs(data, 0);
	}
	data->print += write(1, &c, 1);
	if (data->width && data->minus)
	{
		ft_left_justify_cs(data, 0);
	}
}
