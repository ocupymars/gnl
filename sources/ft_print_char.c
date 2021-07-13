#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_printf *data)
{
	char	c;

	c = va_arg(data->args, int);
	ft_current_data(data, 1);
	if (data->width && !data->dash)
		ft_default_justifycs(data, 0);
	data->print += write(1, &c, 1);
	if (data->dash && data->width)
		ft_left_justifycs(data, 0);
}

int	ft_space(t_printf *data, int count)
{
	count++;
	data->space = 1;
	return (count);
}
