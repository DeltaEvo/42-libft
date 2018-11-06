#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	const char	*odst = dst;
	while (*dst)
		dst++;
	ft_strncpy(dst, src, n);
	return ((char *)odst);
}