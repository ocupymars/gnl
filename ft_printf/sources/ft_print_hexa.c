#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_hexa(t_printf *data, int c)
{
	unsigned int	j;
	int				len;
	char			*str;

	j = va_arg(data->args, unsigned int);
	if (!j)
	{
		ft_no_arguments(data);
		return ;
	}
	len = ft_length_base(j, 16);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	str = ft_itoa_base(str, j, 16, c);
	ft_current_data(data, len);
	ft_default_justify_idpux(data);
	while (str && len-- > 0)
		data->print += write(1, &str[len], 1);
	ft_left_justify_idpux(data);
	free(str);
}
