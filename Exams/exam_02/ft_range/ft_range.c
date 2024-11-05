#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i = 0;
	int size = abs((end - start)) + 1;
	int *array = (int *)malloc(sizeof(int) * size);

	while (i < size)
	{
		if (start < end)
		{
			array[i] = start;
			start++;
			i++;
		}
		else
		{
			array[i] = start;
			start--;
			i++;
		}
	}
		return (array);
}

/*#include <stdio.h>
int main(void)
{
	int *range = ft_range(0, -3);

    if (range)
    {
        for (int i = 0; i < 3 ; i++) // Imprimindo o array
        {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range); // Liberando a memória alocada
    }
    else
    {
        printf("Range is NULL\n");
    }

    return 0;
}*/
