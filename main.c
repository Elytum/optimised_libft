#include <unistd.h>
#include <stdio.h>

#include <limits.h>

#include <stdlib.h>
#include <string.h>

// const char	*recursion(int i, int size, char *ptr)
// {
// 	if (i >= 10)
// 	{
// 		*ptr = i % 10 + '0';
// 		return (putnbr_optimized_recursion(i / 10, size + 1, --ptr));
// 	}
// 	else
// 	{
// 		*ptr = i + '0';
// 		return (ptr);
// 	}
// }

// void	putnbr(int i)
// {
// 	char		buffer[11];
// 	const char	*ptr = recursion(i, 1, buffer);

// 	if (i == )
// 	write(1, ptr, 2);
// 	// write(1, ptr, sizeof(buffer) - (ptr - buffer));
// }

static size_t		number_of_strings(char **s, char c, size_t *len)
{
	size_t			i;
	char const		*ptr = *s;

	*len = 0;
	i = 0;
	while (*ptr == c)
		++ptr;
	*s = (char *)ptr;
	while (*ptr)
	{
		while (*ptr && *ptr != c)
		{
			++*len;
			++ptr;
		}
		++*len;
		++i;
		while (*ptr == c)
			++ptr;
	}
	return (i);
}

void				copy_strings(char ***array, char const *s, char c, size_t size)
{
	char			**fuckit;
	char			*ptr;
	char			**array_ptr;

	fuckit = *array + size + 1;
	array_ptr = *array;
	ptr = (char *)fuckit;
	while (size--)
	{
		*array_ptr++ = ptr;
		while (*s != c)
			*ptr++ = *s++;
		*ptr++ = '\0';
		while (*s == c)
			++s;
	}
	*array_ptr = NULL;
}

void				put_str_array(char **array)
{
	while (*array)
	{
		write(1, *array, strlen(*array));
		write(1, "\n", 1);
		++array;
	}
}

char				**megasplit(char const *s, char c)
{
	size_t			len;
	size_t			size;
	char			**array;
	char			*ptr;

	ptr = (char *)s;
	size = number_of_strings(&ptr, c, &len);
	if (!(array = (char **)malloc(sizeof(char *) *
					((size + 1 + (len >> 3) + ((len % 8) != 0))))))
		return (NULL);
	copy_strings(&array, ptr, c, size);
	return (array);
}

#define TEST_STRING "*salut*les***etudiants*"
#include <string.h>

int		main(void)
{
	char			**array;

	array = megasplit(TEST_STRING, '*');
	put_str_array(array);
	free(array);
	return (0);
}