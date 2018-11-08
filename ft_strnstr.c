/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:41:44 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 15:20:16 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*o_needle = needle;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack && *needle)
		if (*haystack++ == *needle)
			needle++;
		else
		{
			haystack -= needle - o_needle;
			len += needle - o_needle;
			needle = o_needle;
		}
	return (*needle ? 0 : (char *)(haystack - (needle - o_needle)));
}
