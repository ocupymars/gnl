#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_str_length(char *s, t_printf *data, int len)
{
	if (s)
		len = ft_strlen(s);
	if (data->precision > 0 && len > data->precision)
		len = data->precision;
	return (len);
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

void	ft_zero_precision(t_printf *data)
{
	ft_str_length(NULL, data, 0);
	while (data->width--)
		data->print += ft_putchar(' ');
}

void	ft_negative_precision(t_printf *data)
{
	if (data->precision < 0)
		data->print += ft_putchar('0');
	while (!data->width && data->precision-- > 0)
		data->print += ft_putchar('0');
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
		data->print += ft_putchar(' ');
	data->print += ft_putchar('0');
	while (data->dash && --data->width > 0)
		data->print += ft_putchar(' ');
}
