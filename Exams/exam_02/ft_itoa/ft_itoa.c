#include <unistd.h>
#include <stdlib.h>

int	intlen(int n)
{
	int i = 0;
	if (n == 0)
		return 1;
	while (n != 0)
	{
		n /= 10;
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
	int len;
	int i = 0;
	char *result;

	len = intlen(nbr);
	if (nbr < 0)
		i++;
	len = len + i;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '-';
	result[len] = '\0';
	while ((len - 1) >= i)
	{
		result[len - 1] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return result;
}
