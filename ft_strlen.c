#include <stddef.h>
#include <stdint.h>

/*
 * Pseudo vectorisation with normal instructions
 */

size_t ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (1)
	{
		uint32_t part = *(uint32_t *)s;
		if ((part & 0xff) == 0)
			return (len);
		if ((part & 0xff00) == 0)
			return (len + 1);
		if ((part & 0xff0000) == 0)
			return (len + 2);
		if ((part & 0xff000000) == 0)
			return (len + 3);
		len += sizeof(uint32_t);
		s += sizeof(uint32_t);
	}
}
