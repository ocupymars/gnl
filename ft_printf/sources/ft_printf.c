#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	*data;
	int			i;
	int			printing;

	if (!format)
		return (0);
	printing = 0;
	data = (t_printf *)malloc(sizeof(t_printf));
	if (!data)
		return (-1);
	ft_initialise_data(data);
	i = -1;
	va_start(data->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_parse_specifiers(data, format, i + 1);
		else
			printing += write(1, &format[i], 1);
	}
	printing += data->print;
	va_end(data->args);
	free(data);
	return (printing);
}
