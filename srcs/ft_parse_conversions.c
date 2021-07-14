#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_parse_conversions(t_printf *data, const char *format, int count)
{
	if (format[count] == 'p')
		ft_print_pointer_address(data);
	else if (format[count] == 'c')
		ft_print_char(data);
	else if (format[count] == 's')
		ft_print_string(data);
	else if (format[count] == 'x' || format[count] == 'X')
		ft_print_hexa(data, format[count] - 23);
	else if (format[count] == '%')
		ft_print_percent(data);
	else if (format[count] == 'u')
		ft_print_unsigned_int(data);
	else if (format[count] == 'd' || format[count] == 'i')
		ft_print_id(data);
	return (count);
}
