#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_int_double(t_printf *data)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = va_arg(data->args, int);
	if (!j)
	{
		ft_no_arguments(data);
		return ;
	}
	if (j < 0)
		j = ft_plus_ifs(data, j);
	str = ft_itoa(j);
	if (!str)
		return ;
	len = ft_length(j);
	ft_current_data(data, len);
	ft_default_justify_idupx(data);
	while (j && str[i])
		data->print += write(1, &str[i++], 1);
	ft_left_justify_idupx(data);
	free(str);
}

void	ft_print_unsigned_int(t_printf *data)
{
	int				i;
	unsigned int	j;
	int				len;
	char			*str;

	i = 0;
	j = va_arg(data->args, int);
	if (!j)
	{
		ft_no_arguments(data);
		return ;
	}
	str = ft_uitoa(j);
	if (!str)
		return ;
	len = ft_length(j);
	ft_current_data(data, len);
	ft_default_justify_idupx(data);
	while (j && str[i])
		data->print += write(1, &str[i++], 1);
	ft_left_justify_idupx(data);
	free(str);
}
