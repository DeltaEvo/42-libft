char	*ft_strcpy(char *dst, const char *src)
{
	const char	*odst = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return ((char *)odst);
}