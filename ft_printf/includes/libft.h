#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int		ft_putchar(char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
char	*ft_uitoa(unsigned int nb);
void	ft_putnbr(int nbr);
size_t	ft_strlen(const char *s);
int		ft_length(long n);
int		ft_length_base(unsigned long n, int base);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);

#endif
