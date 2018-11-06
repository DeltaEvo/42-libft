#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	const char	*odst = dst;
	while (n--)
		*dst++ = *src ? *src++ : 0;
	*dst = '\0';
	return ((char *)odst);
}