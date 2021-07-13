#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_print_percent(t_printf *data)
{
	if (data->percent)
		data->zero_padding = 1;
	while (data->zero_padding && !data->dash && --data->width > 0)
		data->print += ft_putchar('0');
	while (!data->dash && --data->width > 0)
		data->print += ft_putchar(' ');
	data->print += ft_putchar('%');
	while (data->dash && --data->width > 0)
		data->print += ft_putchar(' ');
}
