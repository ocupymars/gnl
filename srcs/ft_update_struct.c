#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_set_printf_data_string(char *s, t_printf *data, int len)
{
	if (s)
		len = ft_strlen(s);
	if (data->precision > 0 && len > data->precision)
		len = data->precision;
	return (len);
}

void	ft_set_printf_data(t_printf *data, int len)
{
	if (data->sign)
	{
		if (data->width)
			data->width -= 1;
	}
	if (data->precision > 0)
		data->zero = 0;
	if (data->width && data->width >= data->precision)
	{
		if (data->precision > len)
			data->precision -= len;
		else
			data->precision = 0;
		if (!data->is_num_zero)
			data->width = data->width - data->precision - len;
	}
	else if (data->precision > data->width)
	{
		data->width = 0;
		data->precision -= len;
	}
}

void	ft_output_blank(t_printf *data)
{
	ft_set_printf_data_string(NULL, data, 0);
	while (data->width--)
		data->print += ft_putchar(' ');
}

void	ft_write_zero_point(t_printf *data)
{
	if (data->precision < 0)
		data->print += ft_putchar('0');
	while (!data->width && data->precision-- > 0)
		data->print += ft_putchar('0');
}

void	ft_write_zero(t_printf *data)
{
	data->is_num_zero = 1;
	if ((data->width && data->zero) || data->point)
	{
		ft_right_zero(data);
		return ;
	}
	ft_set_printf_data(data, 1);
	while (!data->minus && --data->width > 0)
		data->print += ft_putchar(' ');
	data->print += ft_putchar('0');
	while (data->minus && --data->width > 0)
		data->print += ft_putchar(' ');
}
