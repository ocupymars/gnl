#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_id(t_printf *data)
{
	int		i;
	int		j;
	char	*output;
	int		len;

	i = 0;
	j = va_arg(data->args, int);
	if (!j)
	{
		ft_write_zero(data);
		return ;
	}
	if (j < 0)
		j = ft_plus_ifs(data, j);
	output = ft_itoa(j);
	if (!output)
		return ;
	len = ft_strlen(output);
	ft_set_printf_data(data, len);
	ft_default_justify_idpux(data);
	while (j && output[i])
		data->print += write(1, &output[i++], 1);
	ft_left_justify_idpux(data);
	free(output);
}
