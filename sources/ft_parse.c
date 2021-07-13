#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_parse_conversions(t_printf *data, const char *format, int count)
{
	if (format[count] == 'c')
		ft_print_char(data);
	else if (format[count] == 's')
		ft_print_string(data);
	else if (format[count] == 'p')
		ft_print_pointer_address(data);
	else if (format[count] == 'd' || format[count] == 'i')
		ft_print_int_double(data);
	else if (format[count] == 'u')
		ft_print_unsigned_int(data);
	else if (format[count] == 'x' || format[count] == 'X')
		ft_print_hexa(data, format[count] - 23);
	else if (format[count] == '%')
		ft_print_percent(data);
	return (count);
}

int	ft_parse_specifiers(t_printf *data, const char *format, int count)
{
	while (!(ft_isalpha(format[count]) || format[count] == '%'))
	{
		if (format[count] == '-')
			count = ft_dash(data, format, count);
		if (format[count] == '0')
			count = ft_zero_padding(data, format, count);
		if (format[count] == '.')
			count = ft_precision(data, format, count);
		if (format[count] == '*')
			count = ft_star(data, format, count);
		if (format[count] == ' ')
			count = ft_space(data, count);
		if (ft_isdigit(format[count]))
			count = ft_width(data, format, count);
	}
	ft_parse_conversions(data, format, count);
	ft_reset_data(data);
	return (count);
}
