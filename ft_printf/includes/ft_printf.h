#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_printf
{
	va_list	args;
	int		percent;
	int		space;
	int		zero;
	int		print;
	int		point;
	int		width;
	int		zero_padding;
	int		dash;
	int		plus;
	int		precision;

}				t_printf;

int			ft_parse_conversions(t_printf *data, const char *format, int count);
int			ft_parse_specifiers(t_printf *data, const char *format, int count);
int			ft_star(t_printf *data, const char *format, int count);
int			ft_precision(t_printf *data, const char *format, int count);
int			ft_zero_padding(t_printf *data, const char *format, int count);
int			ft_dash(t_printf *data, const char *format, int count);
int			ft_width(t_printf *data, const char *format, int count);
void		ft_width_ifs(t_printf *data);
int			ft_flags_ifs(char c);
void		ft_precision_ifs(t_printf *data);
int			ft_plus_ifs(t_printf *data, int j);
void		ft_default_justify_idpux(t_printf *data);
void		ft_left_justify_idpux(t_printf *data);
void		ft_default_justify_cs(t_printf *data, int len);
void		ft_left_justify_cs(t_printf *data, int len);
void		ft_leading_zeros(t_printf *data);
void		ft_print_char(t_printf *data);
void		ft_print_hexa(t_printf *data, int c);
void		ft_print_int(t_printf *data);
void		ft_print_unsigned_int(t_printf *data);
void		ft_print_percent(t_printf *data);
int			ft_space(t_printf *data, int count);
void		ft_print_pointer_address(t_printf *data);
void		ft_null_pointer(t_printf *data);
void		ft_print_string(t_printf *data);
t_printf	*ft_initialise_data(t_printf *data);
t_printf	*ft_reset_data(t_printf *data);
int			ft_str_length(char *s, t_printf *data, int len);
void		ft_current_data(t_printf *data, int len);
void		ft_zero_precision(t_printf *data);
void		ft_negative_precision(t_printf *data);
void		ft_no_arguments(t_printf *data);
int			ft_printf(const char *format, ...);

#endif
