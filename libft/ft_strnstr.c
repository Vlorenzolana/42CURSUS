#include "libft.h"

char *ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;

	if (needle[0] == 0)
		return ((char *) str);

	while (str[i] && i < len)
	{
		while (str[i + j] == needle[j] && str[i + j] && i + j < len)
		{
			j++;

		if (needle[j] == 0)
			return ((char *) str + i);
		}

		i++;
		j = 0;
	}
	return (0);
}

