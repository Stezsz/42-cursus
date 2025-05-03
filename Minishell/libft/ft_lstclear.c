/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:36 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:54:17 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	lst = NULL;
}
/*
void	ft_del(void    *content)
{
	free(content);
}
int	main(void)
{
	t_list  *node1 = ft_lstnew(ft_strdup("content1"));
	t_list  *node2 = ft_lstnew(ft_strdup("content2"));

	node1->next = node2;
	printf("%s\n", (char *)(node1->next->content));
	ft_lstclear(&node1, &ft_del);
	printf("%s\n", (char *)(&node1));




}  */
