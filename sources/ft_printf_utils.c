#include "../includes/ft_printf.h"
#include "../includes/libft.h"

t_printf	*ft_initialise_data(t_printf *data)
{
	data->length = 0;
	data->dash = 0;
	data->plus = 0;
	data->space = 0;
	data->zero_padding = 0;
	data->width = 0;
	data->precision = 0;
	data->point = 0;
	data->percent = 0;
	data->print = 0;
	data->zero = 0;
	return (data);
}

t_printf	*ft_reset_data(t_printf *data)
{
	data->length = 0;
	data->dash = 0;
	data->plus = 0;
	data->space = 0;
	data->zero_padding = 0;
	data->width = 0;
	data->precision = 0;
	data->point = 0;
	data->percent = 0;
	data->print = 0;
	data->zero = 0;
	return (data);
}

void	ft_current_data(t_printf *data, int len)
{
	if (data->plus)
	{
		if (data->width)
			data->width -= 1;
	}
	if (data->precision > 0)
		data->zero_padding = 0;
	if (data->width && data->width >= data->precision)
	{
		if (data->precision > len)
			data->precision -= len;
		else
			data->precision = 0;
		if (!data->zero)
			data->width = data->width - data->precision - len;
	}
	else if (data->precision > data->width)
	{
		data->width = 0;
		data->precision -= len;
	}
}

void	ft_negative_precision(t_printf *data)
{
	if (data->precision < 0)
		data->print += write(1, "0", 1);
	if (!data->width && data->precision-- > 0)
		data->print += write(1, "0", 1);
}

void	ft_no_arguments(t_printf *data)
{
	data->zero = 1;
	if ((data->width && data->zero_padding) || data->point)
	{
		ft_leading_zeros(data);
		return ;
	}
	ft_current_data(data, 1);
	while (!data->dash && --data->width > 0)
		data->print += write(1, " ", 1);
	data->print += write(1, "0", 1);
	while (data->dash && --data->width > 0)
		data->print += write(1, " ", 1);
}
