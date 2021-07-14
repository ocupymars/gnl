#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_string(t_printf *data)
{
	char	*output;
	int		i;
	int		len;

	i = 0;
	len = 0;
	output = va_arg(data->args, char *);
	if (!output)
		output = "(null)";
	if (output && data->point == 1 && data->precision == 0)
		return (ft_output_blank(data));
	len = ft_set_printf_data_string(output, data, len);
	if (!data->minus && data->width > len)
		ft_default_justify_cs(data, len);
	if (data->precision > 0)
		while (output[i] && data->precision--)
			data->print += write(1, &output[i++], 1);
	else
		while (output[i])
			data->print += write(1, &output[i++], 1);
	if (output && data->minus && data->width)
		ft_left_justify_cs(data, len);
}
