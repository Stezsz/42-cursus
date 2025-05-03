/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:07:15 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:54:35 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*swap;
	void	*c;

	swap = lst;
	result = NULL;
	while (lst)
	{
		c = f(lst->content);
		swap = ft_lstnew(c);
		if (!swap)
		{
			del(c);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, swap);
		lst = lst->next;
	}
	return (result);
}
/* static void del(void *c)
{
    ft_bzero(c, sizeof(c));
	free(c);
}
static void *ft_tolo(void *s)
{
    char *c = (char *)s;
    int j = 0;
    while (c[j])
    {
        printf("xxx\n");
        if ('A' <= c[j] && c[j] <= 'Z')
        {
            c[j] = c[j] + 32;
            printf("nn\n");
        }
        j++;
    }
    printf("sai\n");
    return (s);
}
int main(void)
{
    t_list *node1 = ft_lstnew(ft_strdup("NOdE1"));
    t_list *node2 = ft_lstnew(ft_strdup("NOdE2"));
    //t_list *node3 = ft_lstnew(ft_strdup("NOdE3"));
    ft_lstadd_front(&node2, node1);
    t_list *m = ft_lstmap(node1, &ft_tolo, del);
    //printf("%s\n", (char *)m->content);
    //free(m);
    ft_lstclear(&m, del);
    ft_lstclear(&node1, del);
} */
