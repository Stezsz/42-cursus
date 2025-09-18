#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

// Calcula distância euclidiana entre dois pontos no plano cartesiano
float    distance(float a[2], float b[2])
{
    return sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}

// Verifica se todas as cidades foram visitadas (condição de parada da recursão)
bool all_visited(bool *visited, ssize_t size)
{
	int i = 0;
	while (i < size)
	{
		if (!visited[i]) // Se alguma cidade não foi visitada
			return false;
		i++;
	}
	return true; // Todas foram visitadas
}

// Algoritmo recursivo para resolver TSP (Traveling Salesman Problem)
// Encontra o menor caminho que visita todas as cidades e retorna ao início
float tsp(float (*array)[2], ssize_t size, int city, float distance_accumulated, bool *visited)
{
	float best_distance = 9999999999999; // Inicializa com valor muito alto
    if (all_visited(visited, size)) // Se visitou todas as cidades
    {
        // Retorna ao ponto inicial (cidade 0) + distância acumulada
        return distance_accumulated + distance(array[city], array[0]);
    }
    // Tenta visitar cada cidade não visitada
    for (int i = 0; i < size; i++)
    {
        if (!visited[i]) // Se a cidade i ainda não foi visitada
        {
            visited[i] = true; // Marca como visitada
            // Recursão: vai para cidade i e acumula distância
            float current_distance = tsp(array, size, i,
                distance_accumulated + distance(array[city], array[i]), visited);
            if (current_distance < best_distance) // Se encontrou caminho melhor
                best_distance = current_distance;
            visited[i] = false; // Backtrack: desmarca para testar outros caminhos
        }
    }
    return best_distance; // Retorna a menor distância encontrada
}

// Conta quantas linhas tem o arquivo (número de cidades)
ssize_t    file_size(FILE *file)
{
    char    *buffer = NULL;
    size_t    n = 0;
    ssize_t ret;

    errno = 0;

    // Conta linhas lendo até EOF
    for (ret = 0; getline(&buffer, &n, file) != -1; ret++);

    free(buffer);
    if (errno || fseek(file, 0, SEEK_SET)) // Volta para o início do arquivo
        return -1;
    return ret; // Retorna número de linhas
}

// Lê coordenadas x,y de cada cidade do arquivo
int        retrieve_file(float (*array)[2], FILE *file)
{
    int tmp;
    // Para cada linha, lê duas coordenadas float separadas por vírgula
    for (size_t i = 0; (tmp = fscanf(file, "%f, %f\n", array[i] + 0, array[i] + 1)) != EOF; i++)
        if (tmp != 2) // Se não conseguiu ler exatamente 2 valores
        {
            errno = EINVAL; // Formato inválido
            return -1;
        }
    if (ferror(file)) // Se houve erro de I/O
        return -1;
    return 0;
}

int        main(int ac, char **av)
{
    char *filename = "stdin";
    FILE *file = stdin; // Por padrão lê da entrada padrão
    if (ac > 1) // Se passou nome do arquivo como argumento
    {
        filename = av[1];
        file = fopen(filename, "r"); // Abre arquivo para leitura
	}

    if (!file)
    {
        fprintf(stderr, "Error opening %s: %m\n", filename);
        return 1;
    }

    ssize_t size = file_size(file); // Conta número de cidades
    if (size == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", filename);
        fclose(file);
        return 1;
    }

    // Aloca array para coordenadas das cidades [x,y]
    float (*array)[2] = calloc(size, sizeof (float [2]));
    if (!array)
    {
        fprintf(stderr, "Error: %m\n");
        fclose(file);
        return 1;
    }

    // Lê as coordenadas do arquivo
    if (retrieve_file(array, file) == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", av[1]);
        fclose(file);
        free(array);
        return 1;
    }
    if (ac > 1)
        fclose(file);
	bool visited[11]; // Array para marcar cidades visitadas (max 11 cidades)
	for (int i = 0; i < size; i++)
		visited[i] = false; // Inicialmente nenhuma cidade foi visitada
    // Executa algoritmo TSP começando da cidade 0 com distância 0
    printf("%.2f\n", tsp(array, size, 0 ,0, visited));
    free(array);
    return (0);
}
