#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	const char	*odst = dst;
	while (*dst)
		dst++;
	ft_strcpy(dst, src);
	return ((char *)odst);
}