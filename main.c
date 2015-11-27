#include <libft.h>

#define TEST_STRING "*salut*les***etudiants*"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void				put_str_array(char **array)
{
	while (*array)
	{
		write(1, *array, strlen(*array));
		write(1, "\n", 1);
		++array;
	}
}

int		main(void)
{
	// char			**array;

	// array = ft_strsplit(TEST_STRING, '*');
	// put_str_array(array);
	// free(array);

	// int				i = 1000000;
	// while (i--)
	// 	ft_putnbr(25453453);

	int				i = 1000000;
	while (i--)
		write(1, ft_itoa(-2147483648), 12);
	return (0);
}