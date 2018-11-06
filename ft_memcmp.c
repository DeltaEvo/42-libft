#include <stddef.h>

int	memcmp(const void *s1, const void *s2, size_t n)
{
	const char *c_s1 = s1;
	const char *c_s2 = s2;

	if (n != 0)
		while (n--)
			if (*c_s1++ != *c_s2++)
				return (*--c_s1 - *--c_s2);
	return (0);
}