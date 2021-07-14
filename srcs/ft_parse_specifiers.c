#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_parse_format(t_printf *data, const char *format, int count)
{
	while (!(ft_isalpha(format[count]) || format[count] == '%'))
	{
		if (format[count] == '.')
			count = ft_precision(data, format, count);
		if (format[count] == ' ')
			count = ft_process_space(data, count);
		if (ft_isdigit(format[count]))
			count = ft_width(data, format, count);
		if (format[count] == '*')
			count = ft_star(data, format, count);
		if (format[count] == '0')
			count = ft_zero_padding(data, format, count);
		if (format[count] == '-')
			count = ft_dash(data, format, count);
	}
	ft_parse_conversions(data, format, count);
	ft_set_printf_default(data);
	return (count);
}
