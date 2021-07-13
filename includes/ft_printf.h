#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

typedef struct			s_printf
{
	va_list		args;
	char	*format;
	int			length;
	int			dash;
	int			plus;
	int			space;
	int			zero_padding;
	int			width;
	int			precision;
	int			point;
	int			percent;
	int			print;
	int			zero;
}						t_printf;

int			ft_printf(const char *format, ...);
int 		ft_flags_ifs(char c);
void		ft_precision_ifs(t_printf *data);
void		ft_width_ifs(t_printf *data);
int 		ft_plus_ifs(t_printf *data, int i);
int			ft_zero_padding(t_printf *data, const char *format, int count);
int			ft_width(t_printf *data, const char *format, int count);
int			ft_precision(t_printf *data, const char *format, int count);
int			ft_star(t_printf *data, const char *format, int count);
int			ft_dash(t_printf *data, const char *format, int count);
int			ft_parse_conversions(t_printf *data, const char *format, int count);
int			ft_parse_specifiers(t_printf *data, const char *format, int count);
void		ft_leading_zeros(t_printf *data);
void		ft_default_justifycs(t_printf *data, int len);
void		ft_left_justifycs(t_printf *data, int len);
void		ft_default_justify_idupx(t_printf *data);
void		ft_left_justify_idupx(t_printf *data);
void		ft_print_char(t_printf *data);
int			ft_space(t_printf *data, int count);
void		ft_print_percent(t_printf *data);
int			ft_str_length(char *s, t_printf *data, int len);
void		ft_zero_precision(t_printf *data);
void		ft_print_string(t_printf *data);
void		ft_print_int_double(t_printf *data);
void		ft_print_unsigned_int(t_printf *data);
void		ft_print_hexa(t_printf *data, int c);
void		ft_print_pointer_address(t_printf *data);
void		ft_null_pointer(t_printf *data);
t_printf	*ft_initialise_data(t_printf *data);
t_printf	*ft_reset_data(t_printf *data);
void		ft_current_data(t_printf *data, int len);
void		ft_negative_precision(t_printf *data);
void		ft_no_arguments(t_printf *data);

#endif