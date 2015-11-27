#ifndef LIBFT_H
# define LIBFT_H

# define TAB_SIZE(tab) ((sizeof(tab) / sizeof(*tab)))

# define MAX_INT_SIZE 11

# define MIN_INT -2147483648
# define MIN_INT_STRING "-2147483648"

char		**ft_strsplit(char const *s, char c);
void		ft_putnbr(int i);
char		*ft_itoa(int i);


#endif
