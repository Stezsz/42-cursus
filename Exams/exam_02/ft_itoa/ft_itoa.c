#include <stdlib.h>

int	intnbr(int nbr)
{
	int i = 0;

	if (nbr == 0)
		return 1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return i;
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return nbr;
}

char	*ft_itoa(int nbr)
{
	int i = 0;
	int len = intnbr(nbr);
	char *result;

	if (nbr < 0)
		i++;
	len += i;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '-';
	if (nbr == 0)
	{
		result[0] = '0';
	}
	result[len] = '\0';
	while (nbr != 0)
	{
		result[len - 1] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len --;
	}
	return result;
}

