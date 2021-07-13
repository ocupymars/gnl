#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_default_justify_idpux(t_printf *data)
{
	if (data->space)
		data->print += ft_putchar(' ');
	if (data->plus && (data->zero_padding
			|| data->dash || (!data->width && !data->precision)))
	{
		data->print += ft_putchar('-');
		data->plus = 0;
	}
	if (!data->dash)
	{
		while (!data->zero_padding && --data->width > -1)
			data->print += ft_putchar(' ');
		while (data->zero_padding && --data->width > -1)
			data->print += ft_putchar('0');
		if (data->plus)
			data->print += ft_putchar('-');
	}
	while (--data->precision > -1)
		data->print += ft_putchar('0');
}

void	ft_left_justify_idpux(t_printf *data)
{
	if (data->dash)
	{
		while (data->dash && data->zero_padding && --data->precision > -1)
			data->print += ft_putchar('0');
		while (data->dash && --data->width > -1)
			data->print += ft_putchar(' ');
	}
}

void	ft_default_justify_cs(t_printf *data, int len)
{
	while (data->zero_padding && data->width-- > len)
		data->print += ft_putchar('0');
	if (!data->zero_padding && data->precision && data->precision < len)
		while (data->width-- > data->precision)
			data->print += ft_putchar(' ');
	else
		while (!data->zero_padding && data->width-- > len)
			data->print += ft_putchar(' ');
}

void	ft_left_justify_cs(t_printf *data, int len)
{
	while (data->zero_padding && data->width-- > len)
		data->print += ft_putchar('0');
	while (!data->zero_padding && data->width-- > len)
		data->print += ft_putchar(' ');
}

void	ft_leading_zeros(t_printf *data)
{
	if (data->width && (data->point || data->zero_padding))
	{
		if (!data->precision)
		{
			while (data->zero_padding && data->width-- > 0)
				data->print += ft_putchar('0');
			while (!data->zero_padding && data->width-- > 0)
				data->print += ft_putchar(' ');
		}
		else
		{
			data->width -= data->precision;
			while (data->dash && data->precision-- > 0)
				data->print += ft_putchar('0');
			while (data->width-- > 0)
				data->print += ft_putchar(' ');
			while (!data->dash && data->precision-- > 0)
				data->print += ft_putchar('0');
		}
	}
	else if (data->point)
		ft_negative_precision(data);
}
