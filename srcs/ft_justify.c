#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_default_justify_idpux(t_printf *data)
{
	if (data->space)
		data->print += ft_putchar(' ');
	if (data->sign && (data->zero
			|| data->minus || (!data->width && !data->precision)))
	{
		data->print += ft_putchar('-');
		data->sign = 0;
	}
	if (!data->minus)
	{
		while (!data->zero && --data->width > -1)
			data->print += ft_putchar(' ');
		while (data->zero && --data->width > -1)
			data->print += ft_putchar('0');
		if (data->sign)
			data->print += ft_putchar('-');
	}
	while (--data->precision > -1)
		data->print += ft_putchar('0');
}

void	ft_left_justify_idpux(t_printf *data)
{
	if (data->minus)
	{
		while (data->minus && data->zero && --data->precision > -1)
			data->print += ft_putchar('0');
		while (data->minus && --data->width > -1)
			data->print += ft_putchar(' ');
	}
}

void	ft_default_justify_cs(t_printf *data, int len)
{
	while (data->zero && data->width-- > len)
		data->print += ft_putchar('0');
	if (!data->zero && data->precision && data->precision < len)
		while (data->width-- > data->precision)
			data->print += ft_putchar(' ');
	else
		while (!data->zero && data->width-- > len)
			data->print += ft_putchar(' ');
}

void	ft_left_justify_cs(t_printf *data, int len)
{
	while (data->zero && data->width-- > len)
		data->print += ft_putchar('0');
	while (!data->zero && data->width-- > len)
		data->print += ft_putchar(' ');
}

void	ft_right_zero(t_printf *data)
{
	if (data->width && (data->point || data->zero))
	{
		if (!data->precision)
		{
			while (data->zero && data->width-- > 0)
				data->print += ft_putchar('0');
			while (!data->zero && data->width-- > 0)
				data->print += ft_putchar(' ');
		}
		else
		{
			data->width -= data->precision;
			while (data->minus && data->precision-- > 0)
				data->print += ft_putchar('0');
			while (data->width-- > 0)
				data->print += ft_putchar(' ');
			while (!data->minus && data->precision-- > 0)
				data->print += ft_putchar('0');
		}
	}
	else if (data->point)
		ft_write_zero_point(data);
}
