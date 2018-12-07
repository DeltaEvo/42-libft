int	ft_atoip(char **str)
{
	long	result;
	char	mod;

	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	result = 0;
	mod = **str == '-' || **str == '+' ? *(*str)++ == '-' : 0;
	while (**str >= '0' && **str <= '9')
			result = result * 10 + *(*str)++ - '0';
	return ((int)(mod ? -result : result));
}

