#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*str;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	if (!(str = malloc(len + 1)))
		return (NULL);
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - len);
}