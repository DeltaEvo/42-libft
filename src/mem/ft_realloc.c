#include "ft/mem.h"
#include <stdlib.h>

void		*ft_realloc(void *o_ptr, size_t oldsize, size_t newsize)
{
	void	*ptr;

	ptr = malloc(newsize);
	if (oldsize)
	{
		ft_memcpy(ptr, o_ptr, oldsize);
		free(o_ptr);
	}
	return (ptr);
}

