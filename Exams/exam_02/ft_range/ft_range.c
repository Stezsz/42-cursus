#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = abs((end - start)) + 1;
	int *range = malloc(sizeof(int) * len);

	while (i < len)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return (range);
}
