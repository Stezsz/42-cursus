/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:18:32 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:54:48 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		counter;

	if (!lst)
		return (0);
	counter = 1;
	temp = lst->next;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
/* int main(void)
{

	t_list *l =  NULL;
//ft_lstsize(l) == 0);
	ft_lstadd_front(&l, ft_lstnew((void*)1));
printf("%d\n", ft_lstsize(l));
	ft_lstadd_front(&l, ft_lstnew((void*)2));
printf("%d\n", ft_lstsize(l));
	write(1, "\n", 1);
	return (0);
}  */
