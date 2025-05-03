/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:12:36 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:56:29 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	start;
	size_t	end;

	if (!s1 || !(set))
		return (NULL);
	start = 0;
	end = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	if (start >= ft_strlen(s1))
		start = 0;
	else
	{
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[end - 1]))
			end--;
	}
	r = malloc(end - start + 1);
	if (r == 0)
		return (0);
	ft_strlcpy(r, s1 + start, end - start + 1);
	return (r);
}

/* int main()
{
	char s1[] = "et";
	printf("%s\n",ft_strtrim(s1, "te"));
}  */
