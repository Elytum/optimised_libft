#include <stdlib.h>

size_t		ft_strlen(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
		++ptr;
	return (ptr - str);
}