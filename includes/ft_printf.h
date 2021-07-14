#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_printf_data
{
	va_list	args;
	int		percent;
	int		space;
	int		is_num_zero;
	int		print;
	int		point;
	int		width;
	int		zero;
	int		minus;
	int		sign;
	int		precision;

}			t_printf;

int			ft_printf(const char *format, ...);
int			ft_width(t_printf *data, const char *format, int count);
int			ft_precision(t_printf *data, const char *format, int count);
int			ft_parse_format(t_printf *data, const char *format, int count);
int			ft_parse_conversions(t_printf *data, const char *format, int count);
int			ft_dash(t_printf *data, const char *format, int count);
int			ft_zero_padding(t_printf *data, const char *format, int count);
int			ft_star(t_printf *data, const char *format, int count);
void		ft_print_char(t_printf *data);
void		ft_print_string(t_printf *data);
void		ft_print_id(t_printf *data);
void		ft_print_unsigned_int(t_printf *data);
void		ft_print_pointer_address(t_printf *data);
void		ft_print_hexa(t_printf *data, int c);
void		ft_default_justify_idpux(t_printf *data);
void		ft_left_justify_idpux(t_printf *data);
void		ft_right_zero(t_printf *data);
void		ft_default_justify_cs(t_printf *data, int len);
void		ft_left_justify_cs(t_printf *data, int len);
void		ft_set_printf_data(t_printf *data, int len);
int			ft_set_printf_data_string(char *s, t_printf *data, int len);
void		ft_output_blank(t_printf *data);
void		ft_write_zero(t_printf *data);
void		ft_write_zero_point(t_printf *data);
void		ft_print_null_pointer(t_printf *data);
void		ft_print_percent(t_printf *data);
int			ft_process_space(t_printf *data, int count);
void		ft_width_ifs(t_printf *data);
void		ft_precision_ifs(t_printf *data);
int			ft_plus_ifs(t_printf *data, int j);
int			ft_flag_ifs(char c);
t_printf	*ft_set_printf(t_printf *data);
t_printf	*ft_set_printf_default(t_printf *data);

#endif
