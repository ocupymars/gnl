#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_hexa(t_printf *data, int c)
{
	int				len;
	char			*str;
	unsigned int	i;

	i = va_arg(data->args, unsigned int);
	if (!i)
	{
		ft_no_arguments(data);
		return ;
	}
	len = ft_length_base(i, 16);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return ;
	str = ft_itoa_base(str, i, 16, c);
	ft_current_data(data, len);
	ft_default_justify_idupx(data);
	while (str && len-- > 0)
		data->print += write(1, &str[len], 1);
	ft_left_justify_idupx(data);
	free(str);
}
