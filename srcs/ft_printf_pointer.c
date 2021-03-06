#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_pointer_address(t_printf *data)
{
	unsigned long	j;
	int				l;

	l = 2;
	j = (unsigned long)va_arg(data->args, void *);
	if (!j && data->point && data->precision > 0)
	{
		ft_print_null_pointer(data);
		return ;
	}
	if (!(!j && data->point))
		l += ft_length_base(j, 16);
	if (!data->precision || data->width > data->precision)
	{
		ft_set_printf_data(data, l);
		ft_default_justify_idpux(data);
	}
	else
		data->precision = data->precision + 2 - l;
	data->print += write(1, "0x", 2);
	while (data->precision-- > 0)
		data->print += ft_putchar('0');
	if (!(!j && data->point))
		data->print += ft_putnbr_base(j, "0123456789abcdef");
	ft_left_justify_idpux(data);
}

void	ft_print_null_pointer(t_printf *data)
{
	if (data->width > data->precision)
	{
		while (data->width-- > (data->precision + 2))
			data->print += ft_putchar(' ');
	}
	data->print += write(1, "0x", 2);
	while (data->precision-- > 0)
		data->print += ft_putchar('0');
}
