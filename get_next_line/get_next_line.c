/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:35:48 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/31 13:35:48 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp; // Armazena dados entre chamadas
	char		buff[BUFFER_SIZE + 1]; // Buffer para leitura
	char		*line; // Linha que será retornada
	int			bytes; // Número de bytes lidos
	int			nl; // Índice do caractere de nova linha

	if (!temp)
		temp = ft_strdup("");

	bytes = read(fd, buff, BUFFER_SIZE); // Lê o arquivo
	while (bytes >= 0)
	{
		buff[bytes] = 0; // Determina o fim
		temp = ft_strjoin(temp, buff); // Junta o lido com o que temos
		nl = check_newline(temp);
		if (nl != -1)
			return(func(&line, &temp, nl));
		if (!bytes && !temp[0])
			break ; // Se leu tudo e temp esta vazio, termina
		if (!bytes)
			return (get_reminder(&temp, 0)); // Se leu tudo e falta algo, retorna o resto
		bytes = read(fd, buff, BUFFER_SIZE); // Lê mais do arquivo
	}
	free(temp);
	temp = NULL;
	return (NULL); // Retorna NULL se houver erro ou fim do arquivo
}

char	*func(char **line, char **temp, int nl)
{
	*line = ft_substr(*temp, 0, nl + 1); // Copia tudo ate nova linha
	*temp = get_reminder(temp, nl + 1); // Atualiza temp com o resto
	return (*line); // Retorna linha completa;
}

char	*get_reminder(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl); // Calcula o len do resto
	reminder = ft_substr(*str, nl, rlen); // Copia o resto para nova str
	free(*str);
	*str = NULL;
	return (reminder); // retorna o resto
}

int	check_newline(char *buff)
{
	int	i = 0;
	while(buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1); // Se n encontrar
}

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
