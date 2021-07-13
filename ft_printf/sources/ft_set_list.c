#include "../includes/ft_printf.h"

t_printf	*ft_initialise_data(t_printf *data)
{
	data->zero_padding = 0;
	data->precision = 0;
	data->point = 0;
	data->zero = 0;
	data->percent = 0;
	data->plus = 0;
	data->dash = 0;
	data->space = 0;
	data->width = 0;
	return (data);
}

t_printf	*ft_reset_data(t_printf *data)
{
	data->plus = 0;
	data->width = 0;
	data->zero_padding = 0;
	data->precision = 0;
	data->point = 0;
	data->space = 0;
	data->dash = 0;
	data->print = 0;
	data->zero = 0;
	data->percent = 0;
	return (data);
}
