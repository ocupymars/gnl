#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int 	ft_flags_ifs(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}

void	ft_precision_ifs(t_printf *data)
{
	if (data->precision == 0 && data->zero_padding == 1)
	{
		data->zero_padding = 0;
		data->percent = 1;
	}
	if (data->precision < 0)
	{
		data->precision = 0;
		data->point = 0;
	}
}

void	ft_width_ifs(t_printf *data)
{
	if (data->width < 0)
	{
		data->width *= -1;
		data->dash = 0;
		data->zero_padding = 0;
	}	
}

int 	ft_plus_ifs(t_printf *data, int i)
{
	data->plus = 1;
	data->space = 0;
	return (i * -1);
}
