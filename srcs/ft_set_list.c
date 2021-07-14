#include "../includes/ft_printf.h"

t_printf	*ft_set_printf_default(t_printf *data)
{
	data->zero = 0;
	data->precision = 0;
	data->point = 0;
	data->is_num_zero = 0;
	data->percent = 0;
	data->sign = 0;
	data->minus = 0;
	data->space = 0;
	data->width = 0;
	return (data);
}

t_printf	*ft_set_printf(t_printf *data)
{
	data->sign = 0;
	data->width = 0;
	data->zero = 0;
	data->precision = 0;
	data->point = 0;
	data->space = 0;
	data->minus = 0;
	data->print = 0;
	data->is_num_zero = 0;
	data->percent = 0;
	return (data);
}
