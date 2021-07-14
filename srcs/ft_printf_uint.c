#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_unsigned_int(t_printf *data)
{
	int				i;
	unsigned int	j;
	char			*output;
	int				len;

	i = 0;
	j = va_arg(data->args, int);
	if (!j)
	{
		ft_write_zero(data);
		return ;
	}
	output = ft_uitoa(j);
	if (!output)
		return ;
	len = ft_length(j);
	ft_set_printf_data(data, len);
	ft_default_justify_idpux(data);
	while (output[i])
		data->print += write(1, &output[i++], 1);
	ft_left_justify_idpux(data);
	free(output);
}
