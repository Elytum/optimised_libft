#include <libft.h>
#include <tests.h>
#include <timer.h>
#include <unistd.h>
#include <stdlib.h>

void				test_strsplit(void)
{
	char			**array;

	array = ft_strsplit(TEST_STRING, '*');
	put_str_array(array);
	free(array);
}

void				test_putnbr(void)
{
	int				i = TEST_NBR;

	start_timer();
	while (i--)
		ft_putnbr(MIN_INT);
	tell_function_delay("putnbr", NULL);
}

void				test_itoa(void)
{
	int				i = TEST_NBR;

	start_timer();
	while (i--)
		write(1, ft_itoa(MIN_INT), 12);
	tell_function_delay("itoa", NULL);
}

int					main(void)
{
	test_strsplit();
	test_putnbr();
	test_itoa();
	return (0);
}