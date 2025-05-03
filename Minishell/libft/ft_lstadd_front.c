/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:15:37 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:53:59 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/* int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("node1"));
	t_list *node2 = ft_lstnew(ft_strdup("node2"));
	ft_lstadd_front(&node2, node1);
	printf("%s\n", (char *)(ft_lstlast(node1)->content));
} */
