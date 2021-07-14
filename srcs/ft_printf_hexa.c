#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_hexa(t_printf *data, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(data->args, unsigned int);
	if (!j)
	{
		ft_write_zero(data);
		return ;
	}
	len = ft_length_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_set_printf_data(data, len);
	ft_default_justify_idpux(data);
	while (num && len-- > 0)
		data->print += write(1, &num[len], 1);
	ft_left_justify_idpux(data);
	free(num);
}
