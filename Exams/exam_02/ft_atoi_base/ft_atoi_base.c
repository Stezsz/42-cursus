int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int digit = 0;

	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break ;
		if (digit >= str_base)
			break ;
		result = result * str_base + digit;
		i++;
	}
	return (result * sign);
}
