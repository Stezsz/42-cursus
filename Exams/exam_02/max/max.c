int		max(int* tab, unsigned int len)
{
	int max;
	int i = 0;

	if (len == 0)
		return 0;
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return max;
}
