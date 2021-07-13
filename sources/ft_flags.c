#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_zero_padding(t_printf *data, const char *format, int count)
{
	int		i;

	i = 0;
	data->zero_padding = 1;
	while (format[count] == '0')
		count++;
	if (ft_isdigit(format[count]))
	{
		i = ft_atoi(&format[count]);
		count += ft_length(i);
	}
	data->width = i;
	return (count);
}

int	ft_width(t_printf *data, const char *format, int count)
{
	int		i;

	i = 0;
	if (ft_isdigit(format[count]))
	{
		i = ft_atoi(&format[count]);
		count += ft_length(i);
	}
	data->width = i;
	if (format[count] == '.')
		count = ft_precision(data, format, count);
	return (count);
}

int	ft_precision(t_printf *data, const char *format, int count)
{
	int		i;

	i = 0;
	data->point = 1;
	if (ft_isdigit(format[count]))
		ft_precision_ifs(data);
	while (format[count] == '0' || ft_flags_ifs(format[count]))
	{
		count++;
		ft_precision_ifs(data);
	}
	if (ft_isdigit(format[count]))
	{
		i = ft_atoi(&format[count]);
		count += ft_length(i);
	}
	data->precision = i;
	if (format[count] == '*')
		count = ft_star(data, format, count);
	while (format[count] == '*')
		count++;
	return (count);
}

int	ft_star(t_printf *data, const char *format, int count)
{
	if (data->point)
	{
		data->precision = va_arg(data->args, int);
		ft_precision_ifs(data);
	}
	else
	{
		data->width = va_arg(data->args, int);
		ft_width_ifs(data);
	}
	if (format[count] == '.')
		count = ft_precision(data, format, count);
	if (format[count] == '*')
		count = ft_star(data, format, count);
	while (format[count] == '*')
		count++;
	return (count);
}	

int	ft_dash(t_printf *data, const char *format, int count)
{
	if (data->dash == 1)
	{
		while (format[count] == '-')
			count++;
		return (count);
	}
	if (data->dash == 1 && data->zero_padding == 1)
		data->zero_padding = 0;
	while (format[count == '-'])
		count = ft_width(data, format, count);
	return (count);
}
