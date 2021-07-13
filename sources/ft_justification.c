#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_leading_zeros(t_printf *data)
{
	if (data->width && (data->point || data->zero_padding))
	{
		if (!data->precision)
		{
			while (data->zero_padding && data->width-- > 0)
				data->print += write(1, "0", 1);
			while (!data->zero_padding && data->width-- > 0)
				data->print += write(1, " ", 1);
		}
		else
		{
			data->width -= data->precision;
			while (!data->dash && data->precision-- > 0)
				data->print += write(1, "0", 1);
			while (data->width-- > 0)
				data->print += write(1, " ", 1);
			while (data->dash && data->precision-- > 0)
				data->print += write(1, "0", 1);
		}
	}
}

void	ft_default_justifycs(t_printf *data, int len)
{
	if (!data->zero_padding && data->precision && data->precision < len)
		while (data->width-- > data->precision)
			data->print += write(1, " ", 1);
	else
		while (!data->zero_padding && data->width-- > len)
			data->print += write(1, " ", 1);
}

void	ft_left_justifycs(t_printf *data, int len)
{
	while (!data->zero_padding && data->width-- > len)
		data->print += write(1, " ", 1);
}

void	ft_default_justify_idupx(t_printf *data)
{
	if (data->space)
		data->print += write(1, "-", 1);
	if (data->plus && (data->zero_padding || (!data->width || !data->precision)
			|| data->dash))
	{
		data->print += write(1, "-", 1);
		data->plus = 0;
	}
	if (!data->dash)
	{
		while (!data->zero_padding && --data->width > -1)
			data->print += write(1, " ", 1);
		while (data->zero_padding && data->width > -1)
			data->print += write(1, "0", 1);
	}
	while (--data->precision > -1)
		data->print += write(1, "0", 1);
}

void	ft_left_justify_idupx(t_printf *data)
{
	if (data->dash)
	{
		while (data->dash && --data->width > -1)
			data->print += write(1, " ", 1);
		while (data->dash && data->zero_padding && --data->precision > -1)
			data->print += write(1, "0", 1);
	}
}
